typedef struct _DOT11_WFD_DEVICE_ENTRY {
  ULONG                             uPhyId;
  DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO PhySpecificInfo;
  DOT11_MAC_ADDRESS                 dot11BSSID;
  DOT11_BSS_TYPE                    dot11BSSType;
  DOT11_MAC_ADDRESS                 TransmitterAddress;
  LONG                              lRSSI;
  ULONG                             uLinkQuality;
  USHORT                            usBeaconPeriod;
  ULONGLONG                         ullTimestamp;
  ULONGLONG                         ullBeaconHostTimestamp;
  ULONGLONG                         ullProbeResponseHostTimestamp;
  USHORT                            usCapabilityInformation;
  ULONG                             uBeaconIEsOffset;
  ULONG                             uBeaconIEsLength;
  ULONG                             uProbeResponseIEsOffset;
  ULONG                             uProbeResponseIEsLength;
}  DOT11_WFD_DEVICE_ENTRY, *PDOT11_WFD_DEVICE_ENTRY;