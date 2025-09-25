typedef struct _OPTCOMBO {
  WORD      cbSize;
  BYTE      Flags;
  WORD      cListItem;
  POPTPARAM pListItem;
  LONG      Sel;
  DWORD     dwReserved[3];
} OPTCOMBO, *POPTCOMBO;