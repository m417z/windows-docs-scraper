typedef struct _EXPLICIT_ACCESS_A {
  DWORD       grfAccessPermissions;
  ACCESS_MODE grfAccessMode;
  DWORD       grfInheritance;
  TRUSTEE_A   Trustee;
} EXPLICIT_ACCESS_A, *PEXPLICIT_ACCESS_A, EXPLICIT_ACCESSA, *PEXPLICIT_ACCESSA;