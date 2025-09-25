typedef struct _HIDP_EXTENDED_ATTRIBUTES {
  UCHAR               NumGlobalUnknowns;
  UCHAR               Reserved[3];
  PHIDP_UNKNOWN_TOKEN GlobalUnknowns;
  ULONG               Data[1];
} HIDP_EXTENDED_ATTRIBUTES, *PHIDP_EXTENDED_ATTRIBUTES;