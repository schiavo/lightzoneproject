<?php

/**
 * @file
 * CleanTalk module admin functions.
 */

/**
 * Cleantalk settings form.
 */
function cleantalk_settings_form($form, &$form_state) {
  $ct_comments_default = 3;

  $ct_authkey = variable_get('cleantalk_authkey', '');
  $ct_comments = variable_get('cleantalk_comments', $ct_comments_default);
  $ct_automod = variable_get('cleantalk_automod', 1);
  $ct_ccf = variable_get('cleantalk_ccf', 0);
  $ct_link = variable_get('cleantalk_link', 0);
  $ct_sfw = variable_get('cleantalk_sfw', 0);
  $ct_wf_silent = variable_get('cleantalk_wf_silent', 0);
  $ct_wf_nomail = variable_get('cleantalk_wf_nomail', 0);

  $form['cleantalk_authkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Access key'),
    '#size' => 20,
    '#maxlength' => 20,
    '#default_value' => $ct_authkey ? $ct_authkey : '',
    '#description' => t(
      'Click <a target="_blank" href="!ct_link">here</a> to get access key.',
      array(
        '!ct_link' => url('http://cleantalk.org/register?platform=drupal'),
      )
    ),
  );

  $form['cleantalk_comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum approved comments per registered user'),
    '#size' => 5,
    '#maxlength' => 5,
    '#default_value' => $ct_comments,
    '#element_validate' => array('element_validate_integer_positive'),
    '#description' => t('Moderate messages of guests and registered users who have approved messages less than this value (must be more than 0).'),
  );

  $form['cleantalk_automod'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable automoderation'),
    '#default_value' => $ct_automod,
    '#description' => t('Automatically publish good messages and put bad ones to admin approvement.') .
    '<br /><span class="admin-enabled">' .
    t('Note: It overrides "Skip comment approval" permissions') .
    '</span>',
  );
  
  $form['cleantalk_ccf'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable custom contact forms checking'),
    '#default_value' => $ct_ccf,
    '#description' => t('Enabling this option will aloow you to check all submissions to your site.'),
  );
  
  $form['cleantalk_sfw'] = array(
    '#type' => 'checkbox',
    '#title' => t('Spam FireWall'),
    '#default_value' => $ct_sfw,
    '#description' => t('This option allows to filter spam bots before they access website. Also reduces CPU usage on hosting server and accelerates pages load time.'),
  );
  
  $form['cleantalk_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tell others about CleanTalk'),
    '#default_value' => $ct_link,
    '#description' => t('Checking this box places a small link under the comment form that lets others know what anti-spam tool protects your site.'),
  );

  $form['cleantalk_wf_silent'] = array(
    '#type' => 'checkbox',
    '#title' => t('WebForm - no moderation messages for visitors'),
    '#default_value' => $ct_wf_silent,
    '#description' => t('Don\'t display messages from CleanTalk moderation servers for WebForm submits.'),
  );

  $form['cleantalk_wf_nomail'] = array(
    '#type' => 'checkbox',
    '#title' => t('WebForm - no spam notification emails'),
    '#default_value' => $ct_wf_nomail,
    '#description' => t('Don\'t send WebForm submission notification emails if spam.'),
  );

  return system_settings_form($form);
}