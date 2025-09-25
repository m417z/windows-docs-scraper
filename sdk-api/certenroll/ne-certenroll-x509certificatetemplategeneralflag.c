typedef enum X509CertificateTemplateGeneralFlag {
  GeneralMachineType = 0x40,
  GeneralCA = 0x80,
  GeneralCrossCA = 0x800,
  GeneralDefault = 0x10000,
  GeneralModified = 0x20000,
  GeneralDonotPersist = 0x1000
} ;