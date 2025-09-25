BOOL GetPointerDeviceProperties(
  [in]            HANDLE                  device,
  [in, out]       UINT32                  *propertyCount,
  [out, optional] POINTER_DEVICE_PROPERTY *pointerProperties
);