typedef struct _WSD_THIS_MODEL_METADATA {
  WSD_LOCALIZED_STRING_LIST *Manufacturer;
  const WCHAR               *ManufacturerUrl;
  WSD_LOCALIZED_STRING_LIST *ModelName;
  const WCHAR               *ModelNumber;
  const WCHAR               *ModelUrl;
  const WCHAR               *PresentationUrl;
  WSDXML_ELEMENT            *Any;
} WSD_THIS_MODEL_METADATA;