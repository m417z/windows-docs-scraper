typedef struct _WIFI_PHY_CAPABILITIES {
  ULONG         Size;
  ULONG         NumPhyTypes;
  WIFI_PHY_INFO *PhyInfoList;
} WIFI_PHY_CAPABILITIES;