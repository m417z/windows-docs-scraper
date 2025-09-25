typedef struct RILPHONEBOOKENTRY {
  DWORD      cbSize;
  DWORD      dwParams;
  DWORD      dwIndex;
  RILADDRESS raAddress;
  WCHAR      wszText[256];
  WCHAR      wszSecondName[256];
  DWORD      dwGroupIdCount;
  DWORD      rgdwGroupId[10];
  DWORD      dwAdditionalNumCount;
  DWORD      dwAdditionalNumSize;
  DWORD      dwAdditionalNumOffset;
  DWORD      dwEmailCount;
  DWORD      dwEmailSize;
  DWORD      dwEmailOffset;
} RILPHONEBOOKENTRY, *LPRILPHONEBOOKENTRY;