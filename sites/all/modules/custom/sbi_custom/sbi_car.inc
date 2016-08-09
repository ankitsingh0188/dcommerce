<?php

function sbi_custom_car_form($form, &$form_state) {

  // Display page 2 if $form_state['page_num'] == 2
  if (!empty($form_state['page_num']) && $form_state['page_num'] == 2) {
    return sbi_custom_car_form_page_two($form, $form_state);
  }

  if (!empty($form_state['page_num']) && $form_state['page_num'] == 3) {
    return sbi_custom_car_form_page_three($form, $form_state);
  }

  // Otherwise we build page 1.
  $form_state['page_num'] = 1;

  // $form['description'] = array(
  //   '#type' => 'item',
  //   '#title' => t('Insurance For'),
  // );
  // $form['site_api_key_fieldset'] = array(
  // '#type' => 'fieldset',
  // // '#title' => t('API Key'),
  // );

  $form['insurance_for'] = array(
    '#type' => 'select',
    '#title' => t('Insruance For'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'New Car' => 'New Car',
      'Roll Over from Other Company Insurance' => 'Roll Over from Other Company Insurance',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['insurance_for']) ? $form_state['values']['insurance_for'] : '',
  );

  $form['customer_type'] = array(
    '#type' => 'select',
    '#title' => t('Customer Type'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'Individual' => 'Individual',
      'Corporate' => 'Corporate',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['customer_type']) ? $form_state['values']['customer_type'] : '',
  );
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => 'Next',
    '#submit' => array('sbi_custom_next_submit'),
    // '#validate' => array('sbi_custom_next_validate'),
  );

  return $form;
}

/**
 * Returns the form for the second page of form_example_tutorial_8().
 *
 * @ingroup form_example
 */
function sbi_custom_car_form_page_two($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Basic Details'),
  );
  
  $form['vehicle_make'] = array(
    '#type' => 'select',
    '#title' => t('Vehicle Make'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'Ashok Leyland37' => 'Ashok Leyland37',
      'Aston Martin' => 'Aston Martin',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['vehicle_make']) ? $form_state['values']['vehicle_make'] : '',
  );

  $form['vehicle_model'] = array(
    '#type' => 'select',
    '#title' => t('Vehicle Model'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'ABC Model' => 'ABC Model',
      'XYZ Model' => 'XYZ Model',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['vehicle_model']) ? $form_state['values']['vehicle_model'] : '',
  );

  $form['vehicle_variant'] = array(
    '#type' => 'select',
    '#title' => t('Vehicle Variant'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'LXI' => 'LXI',
      'VX' => 'VX',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['vehicle_variant']) ? $form_state['values']['vehicle_variant'] : '',
  );

  $form['fuel_type'] = array(
    '#type' => 'select',
    '#title' => t('Fuel Type'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'Petrol' => 'Petrol',
      'Diesel' => 'Diesel',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['fuel_type']) ? $form_state['values']['fuel_type'] : '',
  );

  $form['year_of_manufacturer'] = array(
    '#type' => 'select',
    '#title' => t('Customer Type'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      '2016' => '2016',
      '2015' => '2015',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['year_of_manufacturer']) ? $form_state['values']['year_of_manufacturer'] : '',
  );

  $form['date_of_purchase'] = array(
    '#type' => 'date',
    '#title' => t('Date Of Purchase / Registration'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    // '#options' => array(
    //   '--Select--' => '--Select--',
    //   'Individual' => 'Individual',
    //   'Corporate' => 'Corporate',
    //  ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['date_of_purchase']) ? $form_state['values']['date_of_purchase'] : '',
  );

  $form['rto_location'] = array(
    '#type' => 'textfield',
    '#title' => t('RTO Location'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['rto_location']) ? $form_state['values']['rto_location'] : '',
  );

  $form['rto_city'] = array(
    '#type' => 'textfield',
    '#title' => t('RTO City'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    '#attributes' => array('disabled' => TRUE),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['rto_city']) ? $form_state['values']['rto_city'] : '',
  );

  $form['suggested_idv'] = array(
    '#type' => 'textfield',
    '#title' => t('Suggested IDV'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    '#attributes' => array('disabled' => TRUE),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['suggested_idv']) ? $form_state['values']['suggested_idv'] : '',
  );

  $form['night_parking_pincode'] = array(
    '#type' => 'textfield',
    '#title' => t('Night Parking Pincode'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['night_parking_pincode']) ? $form_state['values']['night_parking_pincode'] : '',
  );

  $form['mobile_no'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile No'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['mobile_no']) ? $form_state['values']['mobile_no'] : '',
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Id'),
    // '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );

  $form['no_of_paid_drivers'] = array(
    '#type' => 'select',
    '#title' => t('No of Paid Drivers'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      '1' => '1',
      '2' => '2',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['no_of_paid_drivers']) ? $form_state['values']['no_of_paid_drivers'] : '',
  );

  $form['avail_discount_voluntary'] = array(
    '#type' => 'select',
    '#title' => t('Do you want to avail discount (Voluntary Deductible)?'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      'yes' => 'Yes',
      'no' => 'No',
     ),
    // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['avail_discount_voluntary']) ? $form_state['values']['avail_discount_voluntary'] : '',
    '#prefix' => '<div class="avail_discount_voluntary">',
    '#suffix' => '</div>',
  );

  $form['avail_discount_voluntary_yes'] = array(
    '#type' => 'select',
    // '#title' => t('Do you want to avail discount (Voluntary Deductible)?'),
    // '#description' => "Please enter your first name.",
    // '#size' => 20,
    // '#maxlength' => 20,
    '#options' => array(
      '--Select--' => '--Select--',
      '2500' => '2500',
      '5000' => '5000',
     ),
    // // '#required' => TRUE,
    '#default_value' => !empty($form_state['values']['avail_discount_voluntary_yes']) ? $form_state['values']['avail_discount_voluntary_yes'] : '',
    '#prefix' => '<div class="avail_discount_voluntary_yes">',
    '#suffix' => '</div>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Calculate Premium'),
    '#submit' => array('sbi_custom_page_two_submit'),
    '#prefix' => '<div class="calc_premium">',
    '#suffix' => '</div>',
  );
  // $form['back'] = array(
  //   '#type' => 'submit',
  //   '#value' => t('Back'),
  //   '#submit' => array('sbi_custom_page_two_back'),
  //   // We won't bother validating the required 'color' field, since they
  //   // have to come back to this page to submit anyway.
  //   '#limit_validation_errors' => array(),
  // );
  return $form;
}


/**
 * Submit handler for form_example_tutorial_8() next button.
 *
 * Capture the values from page one and store them away so they can be used
 * at final submit time.
 *
 * @ingroup form_example
 */
function sbi_custom_next_submit($form, &$form_state) {

  // Values are saved for each page.
  // to carry forward to subsequent pages in the form.
  // and we tell FAPI to rebuild the form.
  $form_state['page_values'][1] = $form_state['values'];

  if (!empty($form_state['page_values'][2])) {
    $form_state['values'] = $form_state['page_values'][2];
  }

  // When form rebuilds, it will look at this to figure which page to build.
  $form_state['page_num'] = 2;
  $form_state['rebuild'] = TRUE;
}

/**
 * Back button handler submit handler.
 *
 * Since #limit_validation_errors = array() is set, values from page 2
 * will be discarded. We load the page 1 values instead.
 *
 * @ingroup form_example
 */
function sbi_custom_page_two_back($form, &$form_state) {
  $form_state['values'] = $form_state['page_values'][1];
  $form_state['page_num'] = 1;
  $form_state['rebuild'] = TRUE;
}


/**
 * The page 2 submit handler.
 *
 * This is the final submit handler. Gather all the data together and output
 * it in a drupal_set_message().
 *
 * @ingroup form_example
 */
function sbi_custom_page_two_submit($form, &$form_state) {
  $form_state['page_values'][2] = $form_state['values'];

  if (!empty($form_state['page_values'][3])) {
    $form_state['values'] = $form_state['page_values'][3];
  }

  // When form rebuilds, it will look at this to figure which page to build.
  $form_state['page_num'] = 3;
  $form_state['rebuild'] = TRUE;
}

function sbi_custom_car_form_page_three($form, &$form_state) {

  // Calculation of SBI Premium
  $premium = 100000;

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t("Your Premium is Rs $premium only."),
  );

  $form['premium'] = array(
    '#type' => 'textfield',
    '#access' => FALSE,
    '#default_value' => $premium,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add To Cart'),
    '#submit' => array('sbi_custom_commerce_add_to_cart_form_premium'),
  );

  return $form;
}

function sbi_custom_premium_submit($form, &$form_state) {
  $page_one_values = $form_state['page_values'][1];
  $page_two_values = $form_state['page_values'][2];
  $page_three_values = $form_state['values'];
  $keyname = '00004201';

  // Include ICICI libraries
  include("Sfa/BillToAddress.php");
  include("Sfa/CardInfo.php");
  include("Sfa/Merchant.php");
  include("Sfa/MPIData.php");
  include("Sfa/ShipToAddress.php");
  include("Sfa/PGResponse.php");
  include("Sfa/PostLibPHP.php");
  include("Sfa/PGReserveData.php");

  //Intialize payment variables
  $oMPI = new MPIData();
  $oCI = new CardInfo();
  $oPostLibphp = new PostLibPHP();
  $oMerchant = new Merchant();
  $oBTA = new BillToAddress();
  $oSTA = new ShipToAddress();
  $oPGResp = new PGResponse();
  $oPGReserveData = new PGReserveData();

  $myip = $_SERVER['REMOTE_ADDR'];
  $txnid = 'Txn' . uniqid();  // TransactionId format of transactionid can be changed.
  $price = $page_three_values['premium']; //This needs to be generated based on the premium.
  $query = 'Order' .  uniqid(); 
  $RESPONSE_URL = 'http://localhost.dcommerce.com/sbi/subscription';
  $oMerchant->setMerchantDetails($keyname, $keyname, $keyname, $myip, $txnid, $query, $RESPONSE_URL, "POST", "INR", "INV123", "req.Sale", $price, "", "", "true", "", "", "");
  $oPGResp = $oPostLibphp->postSSL($oBTA, $oSTA, $oMerchant, $oMPI, $oPGReserveData);
  if ($oPGResp->getRespCode() == '000') {
    $url = $oPGResp->getRedirectionUrl();
    redirectto($url);  // redirect to the ICICI payment gateway if the merchant details are set correctly.
    } 
  else {
    $msg['status'] = '0';
    $msg['message'] = $oPGResp->getRespMessage();
  }
}

/**
 * Validate handler for the next button on first page.
 *
 * @ingroup form_example
 */
// function sbi_custom_next_validate($form, &$form_state) {
//   $insurance_for = $form_state['values']['insurance_for'];
//   $customer_type = $form_state['values']['customer_type'];
//   if ($insurance_for == '--Select--' && $customer_type == '--Select--') {
//     form_set_error('insurance_for', t('Please select insurance for.'));
//     form_set_error('customer_type', t('Please select customer type'));
//   }
// }

function redirectto($url) {
  if (headers_sent()) { ?>
    <html>
      <head>
        <script language="javascript" type="text/javascript">
          window.self.location = '<?php print($url); ?>';
        </script>
      </head>
    </html>
    <?php exit;
  } 
  else {
    header("Location: " . $url);
    exit;
  }
}

function sbi_custom_car_responce() {

}

?>
