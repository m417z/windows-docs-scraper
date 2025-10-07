void GetPortAttributesByWWN(
   [in, HBAType("HBA_WWN")] uint8                                     wwn[8],
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS                            HBAStatus,
   [out, HBAType("HBA_PORTATTRIBUTES")] MSFC_HBAPortAttributesResults PortAttributes
);