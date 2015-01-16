$(document).ready(function() {
    $.get('text.txt', function(data) {
      $("#TestFile").html(data);
    }, 'text');
});