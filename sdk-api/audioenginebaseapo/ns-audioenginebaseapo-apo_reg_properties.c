typedef struct APO_REG_PROPERTIES {
  CLSID    clsid;
  APO_FLAG Flags;
  WCHAR    szFriendlyName[256];
  WCHAR    szCopyrightInfo[256];
  UINT32   u32MajorVersion;
  UINT32   u32MinorVersion;
  UINT32   u32MinInputConnections;
  UINT32   u32MaxInputConnections;
  UINT32   u32MinOutputConnections;
  UINT32   u32MaxOutputConnections;
  UINT32   u32MaxInstances;
  UINT32   u32NumAPOInterfaces;
  IID      iidAPOInterfaceList[1];
} APO_REG_PROPERTIES, *PAPO_REG_PROPERTIES;