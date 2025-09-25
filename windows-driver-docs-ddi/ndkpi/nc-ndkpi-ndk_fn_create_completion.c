NDK_FN_CREATE_COMPLETION NdkFnCreateCompletion;

VOID NdkFnCreateCompletion(
  [in, optional] PVOID Context,
  [in]           NTSTATUS Status,
  [in]           NDK_OBJECT_HEADER *pNdkObject
)
{...}