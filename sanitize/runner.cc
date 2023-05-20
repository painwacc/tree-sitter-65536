// https://github.com/tlaplus-community/tree-sitter-tlaplus/blob/7ba226cf85280c7917d082940022006e6a3b7b6f/test/sanitize/runner.cc

#include "tree_sitter/api.h"
#include <cassert>
#include <fstream>
#include <stdlib.h>

extern "C" const TSLanguage *tree_sitter_small();

int main(int const argc, char const *const argv[]) {
  bool quiet = argc == 3;
  auto const file_path = std::string(argv[1]);
  auto file = std::ifstream(file_path);
  std::string const text((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

  if (!quiet) {
    printf("%s", text.c_str());
  }

  TSParser *parser = ts_parser_new();
  bool language_ok = ts_parser_set_language(parser, tree_sitter_small());
  assert(language_ok);

  TSTree *tree =
      ts_parser_parse_string(parser, NULL, text.c_str(), text.size());
  TSNode root_node = ts_tree_root_node(tree);
  
  if (!quiet) {
    char *parse_tree = ts_node_string(root_node);
    printf("%s\n", parse_tree);
    free(parse_tree);
  }
  
  ts_tree_delete(tree);
  ts_parser_delete(parser);
  return 0;
}
