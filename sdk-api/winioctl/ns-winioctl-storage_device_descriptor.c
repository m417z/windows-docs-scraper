typedef struct _STORAGE_DEVICE_DESCRIPTOR {
  DWORD            Version;
  DWORD            Size;
  BYTE             DeviceType;
  BYTE             DeviceTypeModifier;
  BOOLEAN          RemovableMedia;
  BOOLEAN          CommandQueueing;
  DWORD            VendorIdOffset;
  DWORD            ProductIdOffset;
  DWORD            ProductRevisionOffset;
  DWORD            SerialNumberOffset;
  STORAGE_BUS_TYPE BusType;
  DWORD            RawPropertiesLength;
  BYTE             RawDeviceProperties[1];
} STORAGE_DEVICE_DESCRIPTOR, *PSTORAGE_DEVICE_DESCRIPTOR;