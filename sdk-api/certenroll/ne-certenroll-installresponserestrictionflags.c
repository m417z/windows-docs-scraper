typedef enum InstallResponseRestrictionFlags {
  AllowNone = 0,
  AllowNoOutstandingRequest = 0x1,
  AllowUntrustedCertificate = 0x2,
  AllowUntrustedRoot = 0x4
} ;