NTDSAPI DWORD DsReplicaSyncAllA(
  [in]            HANDLE                                  hDS,
  [in]            LPCSTR                                  pszNameContext,
  [in]            ULONG                                   ulFlags,
  [in]            BOOL(* )(LPVOID,PDS_REPSYNCALL_UPDATEA) pFnCallBack,
  [in, optional]  LPVOID                                  pCallbackData,
  [out, optional] PDS_REPSYNCALL_ERRINFOA                 **pErrors
);