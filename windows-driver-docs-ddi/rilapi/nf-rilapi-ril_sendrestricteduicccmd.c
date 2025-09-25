HRESULT RIL_SendRestrictedUiccCmd(
  HRIL                        hRil,
  LPVOID                      lpContext,
  RILUICCCOMMAND              dwCommand,
  const RILUICCCMDPARAMETERS  *lpParameters,
  const BYTE                  *lpbData,
  DWORD                       dwSize,
  const RILUICCLOCKCREDENTIAL *lpLockVerification
);