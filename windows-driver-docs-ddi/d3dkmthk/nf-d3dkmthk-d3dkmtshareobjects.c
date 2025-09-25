NTSTATUS D3DKMTShareObjects(
  [in]  UINT                cObjects,
  [in]  const D3DKMT_HANDLE *hObjects,
  [in]  POBJECT_ATTRIBUTES  pObjectAttributes,
  [in]  DWORD               dwDesiredAccess,
  [out] HANDLE              *phSharedNtHandle
);