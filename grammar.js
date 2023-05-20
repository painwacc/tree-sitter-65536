module.exports = grammar({
  name: 'YOUR_LANGUAGE_NAME',

  extras: $ => [
    $.line_comment,
    /\s/,
  ],

  rules: {
    source_file: $ => 'hello',
    line_comment: $ => /#[^\n\r]*[\n\r]*/,
  }
});

