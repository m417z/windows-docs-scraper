typedef struct RILRADIOSTATEITEM {
  DWORD                 dwItemId;
  RILRADIOSTATEITEMFLAG dwItemFlag;
  DWORD                 dwItemAttributes;
  union {
    int          intVal;
    unsigned int uintVal;
    WCHAR        wszVal[32];
    int          intArray[16];
    unsigned int uintArray[16];
    BYTE         byteArray[64];
  } RILITEMVALUEUNION;
  RILITEMVALUEUNION     itemValueUnion;
  WCHAR                 wszFriendlyName[32];
  WCHAR                 wszItemValueOptions[256];
} RILRADIOSTATEITEM, *LPRILRADIOSTATEITEM;