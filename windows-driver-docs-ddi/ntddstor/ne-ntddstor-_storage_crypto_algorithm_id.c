typedef enum _STORAGE_CRYPTO_ALGORITHM_ID {
  StorageCryptoAlgorithmUnknown,
  StorageCryptoAlgorithmXTSAES,
  StorageCryptoAlgorithmBitlockerAESCBC,
  StorageCryptoAlgorithmAESECB,
  StorageCryptoAlgorithmESSIVAESCBC,
  StorageCryptoAlgorithmMax,
  StorCryptoAlgorithmUnknown,
  StorCryptoAlgorithmXTSAES,
  StorCryptoAlgorithmBitlockerAESCBC,
  StorCryptoAlgorithmAESECB,
  StorCryptoAlgorithmESSIVAESCBC
} STORAGE_CRYPTO_ALGORITHM_ID, *PSTORAGE_CRYPTO_ALGORITHM_ID;