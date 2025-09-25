typedef enum _NDK_OPERATION_TYPE {
  NdkOperationTypeReceive,
  NdkOperationTypeReceiveAndInvalidate,
  NdkOperationTypeSend,
  NdkOperationTypeFastRegister,
  NdkOperationTypeBind,
  NdkOperationTypeInvalidate,
  NdkOperationTypeRead,
  NdkOperationTypeWrite
} NDK_OPERATION_TYPE;