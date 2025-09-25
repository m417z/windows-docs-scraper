typedef struct {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    OpModeCapability;
  ULONG                    NumOfTXBuffers;
  ULONG                    NumOfRXBuffers;
  BOOLEAN                  MultiDomainCapabilityImplemented;
  ULONG                    NumSupportedPhys;
  PDOT11_PHY_ATTRIBUTES    SupportedPhyAttributes;
  PDOT11_EXTSTA_ATTRIBUTES ExtSTAAttributes;
#if (NDIS_SUPPORT_NDIS620)
  PDOT11_VWIFI_ATTRIBUTES  VWiFiAttributes;
  PDOT11_EXTAP_ATTRIBUTES  ExtAPAttributes;
#endif
#if (NDIS_SUPPORT_NDIS630)
  PDOT11_WFD_ATTRIBUTES    WFDAttributes;
#endif
} NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES, *PNDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES;