module.exports = grammar({
  name: 'small',

  extras: $ => [
    $.line_comment,
    /\s/,
  ],

  rules: {
    source_file: $ => 'hello',
    line_comment: $ => /#[^\n\r]*[\n\r]*/,
  }
});

