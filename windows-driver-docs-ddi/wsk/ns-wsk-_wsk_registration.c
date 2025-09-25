typedef struct _WSK_REGISTRATION {
  ULONGLONG  ReservedRegistrationState;
  PVOID      ReservedRegistrationContext;
  KSPIN_LOCK ReservedRegistrationLock;
} WSK_REGISTRATION, *PWSK_REGISTRATION;