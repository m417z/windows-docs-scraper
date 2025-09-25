HRESULT RIL_SetUiccServiceState(
  HRIL                        hRil,
  LPVOID                      lpContext,
  HUICCAPP                    hUiccApp,
  RILUICCSERVICESERVICE       dwService,
  const RILUICCLOCKCREDENTIAL *lpLockCredential,
  BOOL                        fEnable
);