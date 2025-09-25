typedef enum WbemChangeFlagEnum {
  wbemChangeFlagCreateOrUpdate = 0,
  wbemChangeFlagUpdateOnly = 0x1,
  wbemChangeFlagCreateOnly = 0x2,
  wbemChangeFlagUpdateCompatible = 0,
  wbemChangeFlagUpdateSafeMode = 0x20,
  wbemChangeFlagUpdateForceMode = 0x40,
  wbemChangeFlagStrongValidation = 0x80,
  wbemChangeFlagAdvisory = 0x10000
} ;