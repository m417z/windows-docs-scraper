typedef enum X509CertificateEnrollmentContext {
  ContextNone = 0,
  ContextUser = 0x1,
  ContextMachine = 0x2,
  ContextAdministratorForceMachine = 0x3
} ;