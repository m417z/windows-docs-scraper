typedef enum X509EnrollmentAuthFlags {
  X509AuthNone = 0,
  X509AuthAnonymous = 1,
  X509AuthKerberos = 2,
  X509AuthUsername = 4,
  X509AuthCertificate = 8
} ;