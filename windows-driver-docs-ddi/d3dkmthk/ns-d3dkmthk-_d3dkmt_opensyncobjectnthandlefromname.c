typedef struct _D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME {
  [in]  DWORD             dwDesiredAccess;
  [in]  OBJECT_ATTRIBUTES *pObjAttrib;
  [out] HANDLE            hNtHandle;
} D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME;