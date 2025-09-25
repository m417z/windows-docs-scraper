typedef struct RILPHONEBOOKLOCATION {
  DWORD                      cbSize;
  HUICCAPP                   hUiccApp;
  RILPHONEENTRYSTORELOCATION dwStoreLocation;
  DWORD                      dwIndex;
} RILPHONEBOOKLOCATION, *LPRILPHONEBOOKLOCATION;