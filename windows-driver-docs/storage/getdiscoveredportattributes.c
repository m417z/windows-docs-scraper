void GetDiscoveredPortAttributes(
   [in] uint32                                                        PortIndex,
   [in] uint32                                                        DiscoveredPortIndex,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS                            HBAStatus,
   [out, HBAType("HBA_PORTATTRIBUTES")] MSFC_HBAPortAttributesResults PortAttributes
);