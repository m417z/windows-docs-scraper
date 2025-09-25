typedef struct _FAX_GLOBAL_ROUTING_INFOW {
  DWORD   SizeOfStruct;
  DWORD   Priority;
  LPCWSTR Guid;
  LPCWSTR FriendlyName;
  LPCWSTR FunctionName;
  LPCWSTR ExtensionImageName;
  LPCWSTR ExtensionFriendlyName;
} FAX_GLOBAL_ROUTING_INFOW, *PFAX_GLOBAL_ROUTING_INFOW;