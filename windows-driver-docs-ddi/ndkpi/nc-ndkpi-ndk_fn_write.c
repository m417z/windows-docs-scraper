NDK_FN_WRITE NdkFnWrite;

NTSTATUS NdkFnWrite(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge,
  [in]           UINT64 RemoteAddress,
  [in]           UINT32 RemoteToken,
  [in]           ULONG Flags
)
{...}