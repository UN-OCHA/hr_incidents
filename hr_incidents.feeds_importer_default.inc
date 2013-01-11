<?php
/**
 * @file
 * hr_incidents.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hr_incidents_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_incidents';
  $feeds_importer->config = array(
    'name' => 'CSV Incidents',
    'description' => 'Import incidents from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'incident',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title_field:et:und',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Date',
            'target' => 'field_incident_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Type',
            'target' => 'field_emergency_disaster_type',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Location',
            'target' => 'field_locations',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Emergencies',
            'target' => 'field_emergencies',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Thumbnail',
            'target' => 'field_thumbnail',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Highlights',
            'target' => 'field_incident_highlights',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Situation Overview',
            'target' => 'field_incident_overview',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Humanitarian Needs',
            'target' => 'field_incident_needs',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Humanitarian Response',
            'target' => 'field_incident_response',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Gaps & Constraints',
            'target' => 'field_incident_gaps',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Coordination',
            'target' => 'field_incident_coordination',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Funding',
            'target' => 'field_incident_funding',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Contacts',
            'target' => 'field_contacts',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_incidents'] = $feeds_importer;

  return $export;
}
