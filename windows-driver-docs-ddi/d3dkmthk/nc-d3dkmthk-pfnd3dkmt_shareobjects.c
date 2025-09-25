PFND3DKMT_SHAREOBJECTS Pfnd3dkmtShareobjects;

NTSTATUS Pfnd3dkmtShareobjects(
  UINT cObjects,
  const D3DKMT_HANDLE *hObjects,
  POBJECT_ATTRIBUTES pObjectAttributes,
  DWORD dwDesiredAccess,
  HANDLE *phSharedNtHandle
)
{...}