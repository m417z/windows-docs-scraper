HRESULT RIL_WritePhonebookEntry(
  HRIL                        hRil,
  LPVOID                      lpContext,
  HUICCAPP                    hUiccApp,
  RILPHONEENTRYSTORELOCATION  dwStoreLocation,
  const RILPHONEBOOKENTRY     *lpEntry,
  const RILUICCLOCKCREDENTIAL *lpLockVerification
);