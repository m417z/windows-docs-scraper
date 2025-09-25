typedef struct _WDF_DEVICE_INTERFACE_PROPERTY_DATA {
  ULONG            Size;
  const GUID       *InterfaceClassGUID;
  PCUNICODE_STRING ReferenceString;
  const DEVPROPKEY *PropertyKey;
  LCID             Lcid;
  ULONG            Flags;
} WDF_DEVICE_INTERFACE_PROPERTY_DATA, *PWDF_DEVICE_INTERFACE_PROPERTY_DATA;