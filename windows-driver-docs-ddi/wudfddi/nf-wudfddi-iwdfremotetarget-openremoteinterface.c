HRESULT OpenRemoteInterface(
  [in]           IWDFRemoteInterface         *pRemoteInterface,
  [in, optional] PCWSTR                      pszRelativeFileName,
  [in]           DWORD                       DesiredAccess,
  [in, optional] PUMDF_IO_TARGET_OPEN_PARAMS pOpenParams
);