typedef enum PolicyServerUrlFlags {
  PsfNone = 0,
  PsfLocationGroupPolicy = 1,
  PsfLocationRegistry = 2,
  PsfUseClientId = 4,
  PsfAutoEnrollmentEnabled = 16,
  PsfAllowUnTrustedCA = 32
} ;