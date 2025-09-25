typedef struct _NDIS_SWITCH_PORT_PROPERTY_PROFILE {
  NDIS_OBJECT_HEADER                          Header;
  ULONG                                       Flags;
  NDIS_SWITCH_PORT_PROPERTY_PROFILE_NAME      ProfileName;
  GUID                                        ProfileId;
  NDIS_VENDOR_NAME                            VendorName;
  GUID                                        VendorId;
  UINT32                                      ProfileData;
  GUID                                        NetCfgInstanceId;
  struct {
    UINT32 PciSegmentNumber : 16;
    UINT32 PciBusNumber : 8;
    UINT32 PciDeviceNumber : 5;
    UINT32 PciFunctionNumber : 3;
  } PciLocation;
  UINT32                                      CdnLabelId;
  NDIS_SWITCH_PORT_PROPERTY_PROFILE_CDN_LABEL CdnLabel;
} NDIS_SWITCH_PORT_PROPERTY_PROFILE, *PNDIS_SWITCH_PORT_PROPERTY_PROFILE;