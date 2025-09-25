NDK_FN_INVALIDATE NdkFnInvalidate;

NTSTATUS NdkFnInvalidate(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
  [in]           NDK_OBJECT_HEADER *pNdkMrOrMw,
  [in]           ULONG Flags
)
{...}