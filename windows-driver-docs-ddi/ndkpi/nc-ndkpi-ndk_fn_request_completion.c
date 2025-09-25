NDK_FN_REQUEST_COMPLETION NdkFnRequestCompletion;

VOID NdkFnRequestCompletion(
  [in, optional] PVOID Context,
  [in]           NTSTATUS Status
)
{...}