DXGKDDI_OPM_SET_SIGNING_KEY_AND_SEQUENCE_NUMBERS DxgkddiOpmSetSigningKeyAndSequenceNumbers;

NTSTATUS DxgkddiOpmSetSigningKeyAndSequenceNumbers(
  [in] PVOID MiniportDeviceContext,
  [in] HANDLE ProtectedOutputHandle,
  [in] const DXGKMDT_OPM_ENCRYPTED_PARAMETERS *EncryptedParameters
)
{...}