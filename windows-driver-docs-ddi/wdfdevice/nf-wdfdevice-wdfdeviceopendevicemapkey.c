NTSTATUS WdfDeviceOpenDevicemapKey(
  [in]           WDFDEVICE              Device,
  [in]           PCUNICODE_STRING       KeyName,
  [in]           ACCESS_MASK            DesiredAccess,
  [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
  [out]          WDFKEY                 *Key
);