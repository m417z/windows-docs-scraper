typedef enum EnrollmentEnrollStatus {
  Enrolled = 0x1,
  EnrollPended = 0x2,
  EnrollUIDeferredEnrollmentRequired = 0x4,
  EnrollError = 0x10,
  EnrollUnknown = 0x20,
  EnrollSkipped = 0x40,
  EnrollDenied = 0x100
} ;