typedef struct _WDF_DEVICE_PNP_CAPABILITIES {
  ULONG         Size;
  WDF_TRI_STATE LockSupported;
  WDF_TRI_STATE EjectSupported;
  WDF_TRI_STATE Removable;
  WDF_TRI_STATE DockDevice;
  WDF_TRI_STATE UniqueID;
  WDF_TRI_STATE SilentInstall;
  WDF_TRI_STATE SurpriseRemovalOK;
  WDF_TRI_STATE HardwareDisabled;
  WDF_TRI_STATE NoDisplayInUI;
  ULONG         Address;
  ULONG         UINumber;
} WDF_DEVICE_PNP_CAPABILITIES, *PWDF_DEVICE_PNP_CAPABILITIES;