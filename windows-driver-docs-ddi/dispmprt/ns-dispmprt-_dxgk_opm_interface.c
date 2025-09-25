typedef struct _DXGK_OPM_INTERFACE {
  USHORT                                           Size;
  USHORT                                           Version;
  PVOID                                            Context;
  PINTERFACE_REFERENCE                             InterfaceReference;
  PINTERFACE_DEREFERENCE                           InterfaceDereference;
  DXGKDDI_OPM_GET_CERTIFICATE_SIZE                 DxgkDdiOPMGetCertificateSize;
  DXGKDDI_OPM_GET_CERTIFICATE                      DxgkDdiOPMGetCertificate;
  DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT              DxgkDdiOPMCreateProtectedOutput;
  DXGKDDI_OPM_GET_RANDOM_NUMBER                    DxgkDdiOPMGetRandomNumber;
  DXGKDDI_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS DxgkDdiOPMSetSigningKeyAndSequenceNumbers;
  DXGKDDI_OPM_GET_INFORMATION                      DxgkDdiOPMGetInformation;
  DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION      DxgkDdiOPMGetCOPPCompatibleInformation;
  DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT           DxgkDdiOPMConfigureProtectedOutput;
  DXGKDDI_OPM_DESTROY_PROTECTED_OUTPUT             DxgkDdiOPMDestroyProtectedOutput;
} DXGK_OPM_INTERFACE, *PDXGK_OPM_INTERFACE;