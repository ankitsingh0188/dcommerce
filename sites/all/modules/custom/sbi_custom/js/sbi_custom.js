/**
 * A javascript file for the sbi premium.
 */
(function ($) {
  Drupal.behaviors.sbi_custom = {
    attach: function (context) {
      $('.avail_discount_voluntary_yes').hide();
      $('.avail_discount_voluntary #edit-avail-discount-voluntary').change(function() {
        var result = this.value; // or $(this).val()
        if(result == 'yes') {
          $('.avail_discount_voluntary_yes').show();
        }
      });
      // SBI Premium js starts here.
      $('.form-radio').change(function() {
        $('#edit-actions #edit-next').click();
      });
    }
  };
})(jQuery);

(function ($) {
$(window).load(function() {
  // SBI Premium js starts here.
  $('.form-radio').change(function() {
    $('#edit-actions #edit-next').click();
    });
  });
})(jQuery);
