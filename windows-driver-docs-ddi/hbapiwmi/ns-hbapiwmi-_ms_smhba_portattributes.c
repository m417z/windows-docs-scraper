typedef struct _MS_SMHBA_PORTATTRIBUTES {
  ULONG     PortType;
  ULONG     PortState;
  ULONG     PortSpecificAttributesSize;
  WCHAR     OSDeviceName[256 + 1];
  ULONGLONG Reserved;
  UCHAR     PortSpecificAttributes[1];
} MS_SMHBA_PORTATTRIBUTES, *PMS_SMHBA_PORTATTRIBUTES;