HRESULT RIL_DeletePhonebookEntry(
  HRIL                        hRil,
  LPVOID                      lpContext,
  HUICCAPP                    hUiccApp,
  RILPHONEENTRYSTORELOCATION  dwStoreLocation,
  DWORD                       dwIndex,
  const RILUICCLOCKCREDENTIAL *lpLockVerification
);