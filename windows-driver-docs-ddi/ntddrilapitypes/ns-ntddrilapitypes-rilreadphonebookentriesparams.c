typedef struct RILREADPHONEBOOKENTRIESPARAMS {
  HUICCAPP                   hUiccApp;
  RILPHONEENTRYSTORELOCATION dwStoreLocation;
  DWORD                      dwStartIndex;
  DWORD                      dwEndIndex;
} RILREADPHONEBOOKENTRIESPARAMS, *LPRILREADPHONEBOOKENTRIESPARAMS;