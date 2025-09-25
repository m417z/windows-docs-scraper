typedef struct tagCOMPAREITEMSTRUCT {
  UINT      CtlType;
  UINT      CtlID;
  HWND      hwndItem;
  UINT      itemID1;
  ULONG_PTR itemData1;
  UINT      itemID2;
  ULONG_PTR itemData2;
  DWORD     dwLocaleId;
} COMPAREITEMSTRUCT, *PCOMPAREITEMSTRUCT, *LPCOMPAREITEMSTRUCT;