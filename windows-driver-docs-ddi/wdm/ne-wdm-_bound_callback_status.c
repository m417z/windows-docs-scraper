typedef enum _BOUND_CALLBACK_STATUS {
  BoundExceptionContinueSearch,
  BoundExceptionHandled,
  BoundExceptionError,
  BoundExceptionMaximum
} BOUND_CALLBACK_STATUS, *PBOUND_CALLBACK_STATUS;