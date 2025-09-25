typedef struct _STOR_CRYPTO_OPERATION {
  STOR_CRYPTO_OPERATION_TYPE OperationType;
  ULONG                      OperationBufferLength;
  PVOID                      OperationBuffer;
} STOR_CRYPTO_OPERATION, *PSTOR_CRYPTO_OPERATION;