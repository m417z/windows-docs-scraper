NTDSAPI DWORD DsReplicaSyncAllW(
  [in]            HANDLE                                  hDS,
  [in]            LPCWSTR                                 pszNameContext,
  [in]            ULONG                                   ulFlags,
  [in]            BOOL(* )(LPVOID,PDS_REPSYNCALL_UPDATEW) pFnCallBack,
  [in, optional]  LPVOID                                  pCallbackData,
  [out, optional] PDS_REPSYNCALL_ERRINFOW                 **pErrors
);