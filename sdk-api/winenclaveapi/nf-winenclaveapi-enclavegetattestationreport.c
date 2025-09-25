HRESULT EnclaveGetAttestationReport(
  [in, optional] const UINT8 [ENCLAVE_REPORT_DATA_LENGTH] EnclaveData,
  [out]          PVOID                                    Report,
  [in]           UINT32                                   BufferSize,
  [out]          UINT32                                   *OutputSize
);