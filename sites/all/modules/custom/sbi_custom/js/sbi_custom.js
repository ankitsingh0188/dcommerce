/**
 * @file$("#datepicker").datepicker({ maxDate: new Date, minDate: new Date(2007, 6, 12) });
 
 * A javascript file for the package page.
 */
(function ($) {
  Drupal.behaviors.sbi_custom = {
    attach: function (context) {
      console.log('here');
      $('.avail_discount_voluntary_yes').hide();
      $('.avail_discount_voluntary #edit-avail-discount-voluntary').change(function() {
        var result = this.value; // or $(this).val()
        if(result == 'yes') {
          $('.avail_discount_voluntary_yes').show();
        }
      });
      // $('.calc_premium').click(function(event) {
      //   event.preventDefault();
      //   alert("Your Premium is Rs : 1 Lakh.");
      // });
    }
  };
})(jQuery);