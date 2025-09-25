typedef enum _TRUSTED_INFORMATION_CLASS {
  TrustedDomainNameInformation = 1,
  TrustedControllersInformation,
  TrustedPosixOffsetInformation,
  TrustedPasswordInformation,
  TrustedDomainInformationBasic,
  TrustedDomainInformationEx,
  TrustedDomainAuthInformation,
  TrustedDomainFullInformation,
  TrustedDomainAuthInformationInternal,
  TrustedDomainFullInformationInternal,
  TrustedDomainInformationEx2Internal,
  TrustedDomainFullInformation2Internal,
  TrustedDomainSupportedEncryptionTypes,
  TrustedDomainAuthInformationInternalAes,
  TrustedDomainFullInformationInternalAes
} TRUSTED_INFORMATION_CLASS, *PTRUSTED_INFORMATION_CLASS;