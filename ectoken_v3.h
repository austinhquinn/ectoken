#ifndef ECTOKEN_V3

/// \brief  Initialize the system for encrypting and decrypting ectoken tokens
/// \return 0 on success
///         -1 on failure
int ectoken_init();

/// \brief  Returns the size a buffer needs to be to contain a valid token
/// \return the size of an encrypted, base64 encoded token, with space for a null termination byte
size_t ectoken_required_size(const size_t a_length);

/// \brief  Returns the size a buffer needs to be to contain a valid token
/// \return the size of decrypted token. Will always be at *least* one longer than the final decrypted token.
size_t ectoken_decrypt_required_size(const size_t a_length);

/// \brief   Decrypt and internally validate a provided token
/// \details This function performs decryption and cryptographic validation of the provided token
/// \return  0 on success
///          -1 on failure to decrypt the token
///          -2 on failure to validate the cryptographic tag
///          -3 when provided with invalid arguments
/// \param   ao_plaintext     The output argument that is populated with the plaintext value. Should be a_token_len bytes.
/// \param   ao_plaintext_len This argument should initially point to an integer specifying the size of the buffer at ao_plaintext.
///                           On function exit the integer will be set to the length of the decrypted token
/// \param   a_token          A pointer to the ciphertext
/// \param   a_token_len      The length of the provided ciphertext. 1 <= a_token_len <= 6144
/// \param   a_key            A pointer to the key to use to decrypt. Should be securely generated and at least 32 bytes long.
/// \param   a_key_len        The length of the provided key. 1 <= a_key_len <= 4096
int ectoken_decrypt_token(char* ao_plaintext, int* ao_plaintext_len,
                          const char* a_token, const int a_token_len,
                          const char* a_key, const int a_key_len);


/// \brief   Encrypt and internally validate a provided token
/// \details This function performs encryptiong and cryptographic validation of the provided token
/// \return  0 on success
///          -1 on failure to encrypt the token
///          -2 on failure to gather the cryptographic tag
///          -3 when provided with invalid arguments
/// \param   ao_token         The output argument that is populated with the token value. Should be at least ectoken_encrypt_required_size(a_plaintext_len).
/// \param   ao_token_len     This argument should initially point to an integer specifying the size of the buffer at ao_token.
//                            Should be at least ectoken_encrypt_required_size(a_plaintext_len).
///                           On function exit the integer will be set to the length of the encrypted token
/// \param   a_plaintext      A pointer to the ciphertext
/// \param   a_plaintext_len  The length of the provided ciphertext. Should be less than 4096.
/// \param   a_key            A pointer to the key to use to encrypt. Should be securely generated and at least 32 bytes long.
/// \param   a_key_len        The length of the provided key. 1 <= a_key_len <= 4096
int ectoken_encrypt_token(char* ao_token, int* ao_token_len,
                          const char* a_plaintext, const int a_plaintext_len,
                          const char* a_key, const int a_key_len);

#endif
