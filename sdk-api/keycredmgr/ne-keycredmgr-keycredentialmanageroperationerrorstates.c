typedef enum KeyCredentialManagerOperationErrorStates {
  KeyCredentialManagerOperationErrorStateNone = 0x0,
  KeyCredentialManagerOperationErrorStateDeviceJoinFailure = 0x01,
  KeyCredentialManagerOperationErrorStateTokenFailure = 0x02,
  KeyCredentialManagerOperationErrorStateCertificateFailure = 0x04,
  KeyCredentialManagerOperationErrorStateRemoteSessionFailure = 0x08,
  KeyCredentialManagerOperationErrorStatePolicyFailure = 0x10,
  KeyCredentialManagerOperationErrorStateHardwareFailure = 0x20,
  KeyCredentialManagerOperationErrorStatePinExistsFailure = 0x40
} ;