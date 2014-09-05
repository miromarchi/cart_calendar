<?php
/**
 * @file
 * cart_calendar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cart_calendar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'calendar_date_link_cart_exhibition';
  $strongarm->value = 'calendar';
  $export['calendar_date_link_cart_exhibition'] = $strongarm;

  return $export;
}
