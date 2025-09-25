typedef struct _DXGK_USERMODESUBMISSION_CAPS {
  union {
    struct {
      UINT SecondaryDoorbellSupported : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  } Flags;
  UINT  DoorbellSizeInBytes;
  UINT  SecondaryDoorbellSizeInBytes;
  UCHAR Reserved[16];
} DXGK_USERMODESUBMISSION_CAPS;