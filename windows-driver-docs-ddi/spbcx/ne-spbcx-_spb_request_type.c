typedef enum _SPB_REQUEST_TYPE {
  SpbRequestTypeUndefined,
  SpbRequestTypeRead,
  SpbRequestTypeWrite,
  SpbRequestTypeSequence,
  SpbRequestTypeLockController,
  SpbRequestTypeUnlockController,
  SpbRequestTypeLockConnection,
  SpbRequestTypeUnlockConnection,
  SpbRequestTypeOther,
  SpbRequestTypeMax
} SPB_REQUEST_TYPE, *PSPB_REQUEST_TYPE;