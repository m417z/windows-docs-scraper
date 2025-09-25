typedef enum _DUID_MATCH_STATUS {
  DuidExactMatch,
  DuidSubIdMatch,
  DuidNoMatch,
  DuidErrorGeneral,
  DuidErrorMissingDuid,
  DuidErrorVersionMismatch,
  DuidErrorInvalidDuid,
  DuidErrorInvalidDeviceIdDescSize,
  DuidErrorInvalidDeviceDescSize,
  DuidErrorInvalidLayoutSigSize,
  DuidErrorInvalidLayoutSigVersion,
  DuidErrorMaximum
} DUID_MATCH_STATUS;