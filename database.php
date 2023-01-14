<?php
	class Database {
		private static $dbName = 'dbstatusled';
		private static $dbHost = 'localhost';
		private static $dbUsername = 'ceva';
		private static $dbUserPassword = 'Juliodelgado1451';
		 
		private static $cont  = null;
		 
		public function __construct() {
			die('Init function is not allowed');}
		public static function connect() {
		  // One connection through whole application
		  if ( null == self::$cont ) {     
        try {
          self::$cont =  new PDO( "mysql:host=".self::$dbHost.":3307;"."dbname=".self::$dbName, self::$dbUsername, self::$dbUserPassword); 
        }
        catch(PDOException $e) {
          die($e->getMessage()); 
        }
		  }
		  return self::$cont;
		}
		 
		public static function disconnect() {
			self::$cont = null;
		}
	}
?>