typedef struct _D3DKMT_OPENNTHANDLEFROMNAME {
  [in]  DWORD             dwDesiredAccess;
  [in]  OBJECT_ATTRIBUTES *pObjAttrib;
  [out] HANDLE            hNtHandle;
} D3DKMT_OPENNTHANDLEFROMNAME;