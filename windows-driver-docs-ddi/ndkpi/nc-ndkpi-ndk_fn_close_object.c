NDK_FN_CLOSE_OBJECT NdkFnCloseObject;

NTSTATUS NdkFnCloseObject(
  [in]           NDK_OBJECT_HEADER *pNdkObject,
  [in]           NDK_FN_CLOSE_COMPLETION CloseCompletion,
  [in, optional] PVOID RequestContext
)
{...}