typedef struct _HDAUDIO_DEVICE_INFORMATION_V2 {
  USHORT  Size;
  USHORT  DeviceVersion;
  USHORT  DriverVersion;
  USHORT  CodecsDetected;
  BOOLEAN IsStripingSupported;
  UCHAR   CtrlRevision;
  USHORT  CtrlVendorId;
  USHORT  CtrlDeviceId;
} HDAUDIO_DEVICE_INFORMATION_V2, *PHDAUDIO_DEVICE_INFORMATION_V2;