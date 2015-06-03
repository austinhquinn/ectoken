#ifndef PHP_ECTOKEN_H
#define PHP_ECTOKEN_H 1

#define PHP_ECTOKEN_VERSION "1.1"
#define PHP_ECTOKEN_EXTNAME "ectoken"

// v3
PHP_FUNCTION(ectoken_init);
PHP_FUNCTION(ectoken_decrypt_token);
PHP_FUNCTION(ectoken_encrypt_token);

// v2
PHP_FUNCTION(ectoken_generate);

extern zend_module_entry ectoken_module_entry;
#define phpext_ectoken_ptr &ectoken_module_entry

#endif
