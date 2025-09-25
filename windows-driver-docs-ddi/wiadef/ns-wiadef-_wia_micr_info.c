typedef struct _WIA_MICR_INFO {
  DWORD Size;
  DWORD Page;
  DWORD Length;
  WCHAR Text[1];
} WIA_MICR_INFO;