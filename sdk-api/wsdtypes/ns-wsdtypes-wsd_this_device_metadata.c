typedef struct _WSD_THIS_DEVICE_METADATA {
  WSD_LOCALIZED_STRING_LIST *FriendlyName;
  const WCHAR               *FirmwareVersion;
  const WCHAR               *SerialNumber;
  WSDXML_ELEMENT            *Any;
} WSD_THIS_DEVICE_METADATA;