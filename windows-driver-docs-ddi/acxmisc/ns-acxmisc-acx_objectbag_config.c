typedef struct _ACX_OBJECTBAG_CONFIG {
  ULONG            Size;
  ULONG            Flags;
  WDFKEY           ParentKey;
  PCUNICODE_STRING Name;
  HANDLE           Handle;
} ACX_OBJECTBAG_CONFIG, *PACX_OBJECTBAG_CONFIG;