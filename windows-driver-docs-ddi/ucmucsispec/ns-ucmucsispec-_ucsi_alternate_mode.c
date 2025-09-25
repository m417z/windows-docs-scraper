typedef struct _UCSI_ALTERNATE_MODE {
  UINT16 SVID;
  union {
    struct {
      UINT16 ModeL;
      UINT16 ModeH;
    };
    UINT32 Mode;
  };
} UCSI_ALTERNATE_MODE, *PUCSI_ALTERNATE_MODE;