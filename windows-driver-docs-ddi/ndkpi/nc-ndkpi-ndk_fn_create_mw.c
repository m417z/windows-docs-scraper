NDK_FN_CREATE_MW NdkFnCreateMw;

NTSTATUS NdkFnCreateMw(
  [in]           NDK_PD *pNdkPd,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_MW **ppNdkMw
)
{...}