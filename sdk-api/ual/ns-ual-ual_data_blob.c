typedef struct tagUAL_DATA_BLOB {
  DWORD            Size;
  GUID             RoleGuid;
  GUID             TenantId;
  SOCKADDR_STORAGE Address;
  WCHAR            UserName[MAX_PATH];
} UAL_DATA_BLOB, *PUAL_DATA_BLOB;