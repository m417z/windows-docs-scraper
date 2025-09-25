NDK_FN_CREATE_PD NdkFnCreatePd;

NTSTATUS NdkFnCreatePd(
  [in]           NDK_ADAPTER *pNdkAdapter,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_PD **ppNdkPd
)
{...}