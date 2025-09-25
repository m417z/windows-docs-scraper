typedef enum X509RequestInheritOptions {
  InheritDefault = 0,
  InheritNewDefaultKey = 0x1,
  InheritNewSimilarKey = 0x2,
  InheritPrivateKey = 0x3,
  InheritPublicKey = 0x4,
  InheritKeyMask = 0xf,
  InheritNone = 0x10,
  InheritRenewalCertificateFlag = 0x20,
  InheritTemplateFlag = 0x40,
  InheritSubjectFlag = 0x80,
  InheritExtensionsFlag = 0x100,
  InheritSubjectAltNameFlag = 0x200,
  InheritValidityPeriodFlag = 0x400,
  InheritReserved80000000 = 0x80000000
} ;