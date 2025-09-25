HRESULT Unload(
  HANDLE                     hDownload,
  HRESULT(* )(HANDLE,HANDLE) lpFreeHandle,
  HANDLE                     hUserData
);