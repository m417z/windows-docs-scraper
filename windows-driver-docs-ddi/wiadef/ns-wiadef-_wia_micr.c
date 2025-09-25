typedef struct _WIA_MICR {
  DWORD         Tag;
  DWORD         Version;
  DWORD         Size;
  WCHAR         Placeholder;
  WORD          Reserved;
  DWORD         Count;
  WIA_MICR_INFO Micr[1];
} WIA_MICR;