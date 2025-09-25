typedef struct _RADIUS_VSA_FORMAT {
  BYTE VendorId[4];
  BYTE VendorType;
  BYTE VendorLength;
  BYTE AttributeSpecific[1];
} RADIUS_VSA_FORMAT;