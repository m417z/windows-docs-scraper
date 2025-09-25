typedef struct _DOT11_WFD_DEVICE_INFO {
  NDIS_OBJECT_HEADER    Header;
  DOT11_MAC_ADDRESS     DeviceAddress;
  USHORT                ConfigMethods;
  DOT11_WPS_DEVICE_TYPE PrimaryDeviceType;
  DOT11_WPS_DEVICE_NAME DeviceName;
} DOT11_WFD_DEVICE_INFO, *PDOT11_WFD_DEVICE_INFO;