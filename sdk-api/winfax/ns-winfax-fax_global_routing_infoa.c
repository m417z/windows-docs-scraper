typedef struct _FAX_GLOBAL_ROUTING_INFOA {
  DWORD  SizeOfStruct;
  DWORD  Priority;
  LPCSTR Guid;
  LPCSTR FriendlyName;
  LPCSTR FunctionName;
  LPCSTR ExtensionImageName;
  LPCSTR ExtensionFriendlyName;
} FAX_GLOBAL_ROUTING_INFOA, *PFAX_GLOBAL_ROUTING_INFOA;