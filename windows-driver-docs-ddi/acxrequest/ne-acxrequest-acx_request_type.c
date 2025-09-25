typedef enum _ACX_REQUEST_TYPE {
  AcxRequestTypeUnknown,
  AcxRequestTypeAny,
  AcxRequestTypeCreate,
  AcxRequestTypeProperty,
  AcxRequestTypeMethod,
  AcxRequestTypeEvent,
  AcxRequestTypeResetState,
  AcxRequestTypeMax
} ACX_REQUEST_TYPE, *PACX_REQUEST_TYPE;