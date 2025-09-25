typedef struct _OPTITEM {
  WORD      cbSize;
  BYTE      Level;
  BYTE      DlgPageIdx;
  DWORD     Flags;
  ULONG_PTR UserData;
  LPTSTR    pName;
  union {
    LONG   Sel;
    LPTSTR pSel;
  } DUMMYUNIONNAME;
  union {
    PEXTCHKBOX pExtChkBox;
    PEXTPUSH   pExtPush;
  } DUMMYUNIONNAME2;
  POPTTYPE  pOptType;
  DWORD     HelpIndex;
  BYTE      DMPubID;
  BYTE      UserItemID;
  WORD      wReserved;
  POIEXT    pOIExt;
  ULONG_PTR dwReserved[3];
} OPTITEM, *POPTITEM;