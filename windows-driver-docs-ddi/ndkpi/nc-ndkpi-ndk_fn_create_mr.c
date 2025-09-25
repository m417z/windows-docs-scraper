NDK_FN_CREATE_MR NdkFnCreateMr;

NTSTATUS NdkFnCreateMr(
  [in]           NDK_PD *pNdkPd,
  [in]           BOOLEAN FastRegister,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_MR **ppNdkMr
)
{...}