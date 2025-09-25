typedef struct _WDF_DEVICE_PROPERTY_DATA {
  ULONG            Size;
  const DEVPROPKEY *PropertyKey;
  LCID             Lcid;
  ULONG            Flags;
} WDF_DEVICE_PROPERTY_DATA, *PWDF_DEVICE_PROPERTY_DATA;