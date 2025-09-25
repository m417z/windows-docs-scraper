typedef struct _NDK_RESULT {
  NTSTATUS Status;
  ULONG    BytesTransferred;
  PVOID    QPContext;
  PVOID    RequestContext;
} NDK_RESULT;