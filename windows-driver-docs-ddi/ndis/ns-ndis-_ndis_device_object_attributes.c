typedef struct _NDIS_DEVICE_OBJECT_ATTRIBUTES {
  NDIS_OBJECT_HEADER Header;
  PNDIS_STRING       DeviceName;
  PNDIS_STRING       SymbolicName;
  PDRIVER_DISPATCH   *MajorFunctions;
  ULONG              ExtensionSize;
  PCUNICODE_STRING   DefaultSDDLString;
  LPCGUID            DeviceClassGuid;
} NDIS_DEVICE_OBJECT_ATTRIBUTES, *PNDIS_DEVICE_OBJECT_ATTRIBUTES;