typedef struct RILDELETEPHONEBOOKENTRYPARAMS {
  HUICCAPP                   hUiccApp;
  RILPHONEENTRYSTORELOCATION dwStoreLocation;
  DWORD                      dwIndex;
  BOOL                       fHasLockVerification;
  RILUICCLOCKCREDENTIAL      lockVerification;
} RILDELETEPHONEBOOKENTRYPARAMS, *LPRILDELETEPHONEBOOKENTRYPARAMS;