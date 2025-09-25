typedef enum _SECURE_ELEMENT_EVENT_TYPE {
  ExternalReaderArrival,
  ExternalReaderDeparture,
  ApplicationSelected,
  Transaction,
  HceActivated,
  HceDeactivated,
  ExternalFieldEnter,
  ExternalFieldExit
} SECURE_ELEMENT_EVENT_TYPE, *PSECURE_ELEMENT_EVENT_TYPE;