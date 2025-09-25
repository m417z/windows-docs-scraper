NDK_FN_READ NdkFnRead;

NTSTATUS NdkFnRead(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge,
  [in]           UINT64 RemoteAddress,
  [in]           UINT32 RemoteToken,
  [in]           ULONG Flags
)
{...}