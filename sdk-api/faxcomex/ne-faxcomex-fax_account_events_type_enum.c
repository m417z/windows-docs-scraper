typedef enum FAX_ACCOUNT_EVENTS_TYPE_ENUM {
  faetNONE = 0,
  faetIN_QUEUE = 0x1,
  faetOUT_QUEUE = 0x2,
  faetIN_ARCHIVE = 0x4,
  faetOUT_ARCHIVE = 0x8,
  faetFXSSVC_ENDED = 0x10
} ;