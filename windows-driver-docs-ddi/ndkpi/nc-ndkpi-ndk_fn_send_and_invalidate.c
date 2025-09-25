NDK_FN_SEND_AND_INVALIDATE NdkFnSendAndInvalidate;

NTSTATUS NdkFnSendAndInvalidate(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge,
  [in]           ULONG Flags,
  [in]           UINT32 RemoteToken
)
{...}