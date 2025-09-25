typedef struct _QUERY_INTERFACE {
  const GUID *InterfaceType;
  USHORT     Size;
  USHORT     Version;
  PINTERFACE Interface;
  PVOID      InterfaceSpecificData;
  ULONG      DeviceUid;
} QUERY_INTERFACE, *PQUERY_INTERFACE;