typedef struct _SP_DEVINFO_DATA {
  DWORD     cbSize;
  GUID      ClassGuid;
  DWORD     DevInst;
  ULONG_PTR Reserved;
} SP_DEVINFO_DATA, *PSP_DEVINFO_DATA;