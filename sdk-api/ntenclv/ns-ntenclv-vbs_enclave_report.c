typedef struct VBS_ENCLAVE_REPORT {
  UINT32           ReportSize;
  UINT32           ReportVersion;
  UINT8            EnclaveData[ENCLAVE_REPORT_DATA_LENGTH];
  ENCLAVE_IDENTITY EnclaveIdentity;
} VBS_ENCLAVE_REPORT;