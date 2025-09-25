typedef struct _FAX_ROUTING_METHODW {
  DWORD   SizeOfStruct;
  DWORD   DeviceId;
  BOOL    Enabled;
  LPCWSTR DeviceName;
  LPCWSTR Guid;
  LPCWSTR FriendlyName;
  LPCWSTR FunctionName;
  LPCWSTR ExtensionImageName;
  LPCWSTR ExtensionFriendlyName;
} FAX_ROUTING_METHODW, *PFAX_ROUTING_METHODW;