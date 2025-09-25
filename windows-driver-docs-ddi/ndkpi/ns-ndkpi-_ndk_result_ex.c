typedef struct _NDK_RESULT_EX {
  NTSTATUS           Status;
  ULONG              BytesTransferred;
  PVOID              QPContext;
  PVOID              RequestContext;
  NDK_OPERATION_TYPE Type;
  ULONG              ProviderErrorCode;
  ULONG_PTR          TypeSpecificCompletionOutput;
} NDK_RESULT_EX;