MI_INLINE MI_Result MI_Application_NewHostedProvider(
  [in]            MI_Application    *application,
  [in]            const MI_Char     *namespaceName,
  [in]            const MI_Char     *providerName,
  [in]            MI_MainFunction   mi_Main,
  [out, optional] MI_Instance       **extendedError,
  [out]           MI_HostedProvider *hostedProvider
);