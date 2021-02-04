# lightzoneproject

To run the site locally.

git clone <remote repo url>
cd lightzoneproject 
lando start

You might have to update database connection in settings.php

      'database' => 'drupal7',
      'username' => 'drupal7',
      'password' => 'drupal7',
      'host' => 'database',
      'port' => '3306',
      'driver' => 'mysql',
