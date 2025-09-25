typedef enum _BLUETOOTH_AUTHENTICATION_REQUIREMENTS {
  BLUETOOTH_MITM_ProtectionNotRequired = 0,
  BLUETOOTH_MITM_ProtectionRequired = 0x1,
  BLUETOOTH_MITM_ProtectionNotRequiredBonding = 0x2,
  BLUETOOTH_MITM_ProtectionRequiredBonding = 0x3,
  BLUETOOTH_MITM_ProtectionNotRequiredGeneralBonding = 0x4,
  BLUETOOTH_MITM_ProtectionRequiredGeneralBonding = 0x5,
  BLUETOOTH_MITM_ProtectionNotDefined = 0xff
} BLUETOOTH_AUTHENTICATION_REQUIREMENTS;