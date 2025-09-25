typedef struct _WWAN_TLV_IE {
  WWAN_TLV_TYPE Type;
  UCHAR         Reserved;
  UCHAR         PaddingLength;
  ULONG         DataLength;
} WWAN_TLV_IE, *PWWAN_TLV_IE;