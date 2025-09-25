typedef struct _EXPLICIT_ACCESS_W {
  DWORD       grfAccessPermissions;
  ACCESS_MODE grfAccessMode;
  DWORD       grfInheritance;
  TRUSTEE_W   Trustee;
} EXPLICIT_ACCESS_W, *PEXPLICIT_ACCESS_W, EXPLICIT_ACCESSW, *PEXPLICIT_ACCESSW;