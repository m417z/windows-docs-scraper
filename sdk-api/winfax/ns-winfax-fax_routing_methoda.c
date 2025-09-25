typedef struct _FAX_ROUTING_METHODA {
  DWORD  SizeOfStruct;
  DWORD  DeviceId;
  BOOL   Enabled;
  LPCSTR DeviceName;
  LPCSTR Guid;
  LPCSTR FriendlyName;
  LPCSTR FunctionName;
  LPCSTR ExtensionImageName;
  LPCSTR ExtensionFriendlyName;
} FAX_ROUTING_METHODA, *PFAX_ROUTING_METHODA;