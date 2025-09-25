typedef enum _COPP_StatusFlags {
  COPP_StatusNormal = 0x00,
  COPP_LinkLost = 0x01,
  COPP_RenegotiationRequired = 0x02,
  COPP_StatusFlagsReserved = 0xFFFFFFFC
} COPP_StatusFlags;