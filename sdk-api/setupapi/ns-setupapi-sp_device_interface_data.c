typedef struct _SP_DEVICE_INTERFACE_DATA {
  DWORD     cbSize;
  GUID      InterfaceClassGuid;
  DWORD     Flags;
  ULONG_PTR Reserved;
} SP_DEVICE_INTERFACE_DATA, *PSP_DEVICE_INTERFACE_DATA;