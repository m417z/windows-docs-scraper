typedef enum _MP_STORAGE_DIAGNOSTIC_TARGET_TYPE {
  MpStorageDiagnosticTargetTypeUndefined = 0,
  MpStorageDiagnosticTargetTypeMiniport = 2,
  MpStorageDiagnosticTargetTypeHbaFirmware,
  MpStorageDiagnosticTargetTypeMax
} MP_STORAGE_DIAGNOSTIC_TARGET_TYPE, *PMP_STORAGE_DIAGNOSTIC_TARGET_TYPE;