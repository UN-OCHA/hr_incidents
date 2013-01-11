<?php
/**
 * @file
 * hr_incidents.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hr_incidents_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|incident|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'incident';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'teaser_labels' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|incident|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hr_incidents_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|incident|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'incident';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'teaser_labels',
        4 => 'title',
      ),
      'left' => array(
        1 => 'field_thumbnail',
      ),
      'footer' => array(
        2 => 'node_link',
      ),
      'right' => array(
        3 => 'field_incident_date',
        5 => 'field_emergency_disaster_type',
        6 => 'field_incident_highlights',
      ),
    ),
    'fields' => array(
      'teaser_labels' => 'header',
      'field_thumbnail' => 'left',
      'node_link' => 'footer',
      'field_incident_date' => 'right',
      'title' => 'header',
      'field_emergency_disaster_type' => 'right',
      'field_incident_highlights' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|incident|teaser'] = $ds_layout;

  return $export;
}
