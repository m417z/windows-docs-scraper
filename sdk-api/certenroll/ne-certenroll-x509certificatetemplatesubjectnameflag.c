typedef enum X509CertificateTemplateSubjectNameFlag {
  SubjectNameEnrolleeSupplies = 0x1,
  SubjectNameRequireDirectoryPath = 0x80000000,
  SubjectNameRequireCommonName = 0x40000000,
  SubjectNameRequireEmail = 0x20000000,
  SubjectNameRequireDNS = 0x10000000,
  SubjectNameAndAlternativeNameOldCertSupplies = 0x8,
  SubjectAlternativeNameEnrolleeSupplies = 0x10000,
  SubjectAlternativeNameRequireDirectoryGUID = 0x1000000,
  SubjectAlternativeNameRequireUPN = 0x2000000,
  SubjectAlternativeNameRequireEmail = 0x4000000,
  SubjectAlternativeNameRequireSPN = 0x800000,
  SubjectAlternativeNameRequireDNS = 0x8000000,
  SubjectAlternativeNameRequireDomainDNS = 0x400000
} ;