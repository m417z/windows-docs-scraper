typedef struct _WIA_PATCH_CODES {
  DWORD               Tag;
  DWORD               Version;
  DWORD               Size;
  DWORD               Count;
  WIA_PATCH_CODE_INFO PatchCodes[1];
} WIA_PATCH_CODES;