<?php
/**
 * @file
 * cart_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cart_calendar_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cart_view_calendar2';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Cart calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['multiday_hidden'] = array(
    'field_cart_date' => 'field_cart_date',
    'field_cart_exhibit_type' => 'field_cart_exhibit_type',
  );
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['calendar_date_link'] = 'cart_exhibition';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'cart_catalog' => '#ffffff',
    'cart_exhibition' => '#ffffff',
    'cart_insta_item' => '#ffffff',
    'cart_organization' => '#ffffff',
    'cart_person' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_cart_exhibit_type' => '2',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    11 => '#f8b820',
    12 => '#11100E',
    1 => '#c41068',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cart_date']['id'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['field'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['label'] = '';
  $handler->display->display_options['fields']['field_cart_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cart_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['delta_offset'] = '0';
  /* Field: Content: Exhibit type */
  $handler->display->display_options['fields']['field_cart_exhibit_type']['id'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['table'] = 'field_data_field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cart_date) */
  $handler->display->display_options['sorts']['field_cart_date_value']['id'] = 'field_cart_date_value';
  $handler->display->display_options['sorts']['field_cart_date_value']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['sorts']['field_cart_date_value']['field'] = 'field_cart_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
  );
  $handler->display->display_options['path'] = 'calendar/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['multiday_hidden'] = array(
    'field_cart_date' => 'field_cart_date',
    'field_cart_exhibit_type' => 'field_cart_exhibit_type',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['calendar_date_link'] = 'cart_exhibition';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'cart_catalog' => '#ffffff',
    'cart_exhibition' => '#ffffff',
    'cart_insta_item' => '#ffffff',
    'cart_organization' => '#ffffff',
    'cart_person' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_cart_exhibit_type' => '2',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    11 => '#f8b820',
    12 => '#11100E',
    1 => '#c41068',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
  );
  $handler->display->display_options['path'] = 'calendar/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['multiday_hidden'] = array(
    'field_cart_date' => 'field_cart_date',
    'field_cart_exhibit_type' => 'field_cart_exhibit_type',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['calendar_date_link'] = 'cart_exhibition';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'cart_catalog' => '#ffffff',
    'cart_exhibition' => '#ffffff',
    'cart_insta_item' => '#ffffff',
    'cart_organization' => '#ffffff',
    'cart_person' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_cart_exhibit_type' => '2',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    11 => '#f8b820',
    12 => '#11100E',
    1 => '#c41068',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
  );
  $handler->display->display_options['path'] = 'calendar/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cart_date']['id'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['field'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['label'] = '';
  $handler->display->display_options['fields']['field_cart_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cart_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
  );
  $handler->display->display_options['path'] = 'calendar/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['multiday_hidden'] = array(
    'field_cart_date' => 'field_cart_date',
    'field_cart_exhibit_type' => 'field_cart_exhibit_type',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'taxonomy';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'cart_catalog' => '#ffffff',
    'cart_exhibition' => '#ffffff',
    'cart_organization' => '#ffffff',
    'cart_person' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_cart_exhibit_type' => '2',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    11 => '#0f9c8d',
    1 => '#c41068',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cart_date']['id'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['field'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['label'] = '';
  $handler->display->display_options['fields']['field_cart_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cart_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
  );
  $handler->display->display_options['block_description'] = 'Mini calendar';

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming exhibits';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cart_image']['id'] = 'field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['table'] = 'field_data_field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['field'] = 'field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['label'] = '';
  $handler->display->display_options['fields']['field_cart_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cart_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cart_date']['id'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['field'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['label'] = '';
  $handler->display->display_options['fields']['field_cart_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_cart_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['delta_offset'] = '0';
  /* Field: Content: Exhibit type */
  $handler->display->display_options['fields']['field_cart_exhibit_type']['id'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['table'] = 'field_data_field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cart_date.field_cart_date_value' => 'field_data_field_cart_date.field_cart_date_value',
    'field_data_field_cart_date.field_cart_date_value2' => 'field_data_field_cart_date.field_cart_date_value2',
  );
  $handler->display->display_options['block_description'] = 'Upcoming';

  /* Display: Pane: upcomings */
  $handler = $view->new_display('panel_pane', 'Pane: upcomings', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming exhibits';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'exhibit';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_cart_image']['id'] = 'field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['table'] = 'field_data_field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['field'] = 'field_cart_image';
  $handler->display->display_options['fields']['field_cart_image']['label'] = '';
  $handler->display->display_options['fields']['field_cart_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cart_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cart_date']['id'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['field'] = 'field_cart_date';
  $handler->display->display_options['fields']['field_cart_date']['label'] = '';
  $handler->display->display_options['fields']['field_cart_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cart_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cart_date']['delta_offset'] = '0';
  /* Field: Content: Exhibit type */
  $handler->display->display_options['fields']['field_cart_exhibit_type']['id'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['table'] = 'field_data_field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['field'] = 'field_cart_exhibit_type';
  $handler->display->display_options['fields']['field_cart_exhibit_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cart_exhibition' => 'cart_exhibition',
  );
  /* Filter criterion: Content: Date -  start date (field_cart_date) */
  $handler->display->display_options['filters']['field_cart_date_value']['id'] = 'field_cart_date_value';
  $handler->display->display_options['filters']['field_cart_date_value']['table'] = 'field_data_field_cart_date';
  $handler->display->display_options['filters']['field_cart_date_value']['field'] = 'field_cart_date_value';
  $handler->display->display_options['filters']['field_cart_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cart_date_value']['expose']['operator_id'] = 'field_cart_date_value_op';
  $handler->display->display_options['filters']['field_cart_date_value']['expose']['label'] = 'Date -  start date (field_cart_date)';
  $handler->display->display_options['filters']['field_cart_date_value']['expose']['operator'] = 'field_cart_date_value_op';
  $handler->display->display_options['filters']['field_cart_date_value']['expose']['identifier'] = 'field_cart_date_value';
  $handler->display->display_options['filters']['field_cart_date_value']['default_date'] = 'now';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['cart_view_calendar2'] = $view;

  return $export;
}
