typedef enum _WDF_PNP_CAPABILITY {
  WdfPnpCapInvalid,
  WdfPnpCapLockSupported,
  WdfPnpCapEjectSupported,
  WdfPnpCapRemovable,
  WdfPnpCapDockDevice,
  WdfPnpCapSurpriseRemovalOk,
  WdfPnpCapNoDisplayInUI,
  WdfPnpCapMaximum
} WDF_PNP_CAPABILITY;