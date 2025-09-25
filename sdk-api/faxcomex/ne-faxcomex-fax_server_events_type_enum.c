typedef enum FAX_SERVER_EVENTS_TYPE_ENUM {
  fsetNONE = 0,
  fsetIN_QUEUE = 0x1,
  fsetOUT_QUEUE = 0x2,
  fsetCONFIG = 0x4,
  fsetACTIVITY = 0x8,
  fsetQUEUE_STATE = 0x10,
  fsetIN_ARCHIVE = 0x20,
  fsetOUT_ARCHIVE = 0x40,
  fsetFXSSVC_ENDED = 0x80,
  fsetDEVICE_STATUS = 0x100,
  fsetINCOMING_CALL = 0x200
} ;