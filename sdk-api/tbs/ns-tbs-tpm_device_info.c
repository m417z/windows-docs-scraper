typedef struct _TPM_DEVICE_INFO {
  UINT32 structVersion;
  UINT32 tpmVersion;
  UINT32 tpmInterfaceType;
  UINT32 tpmImpRevision;
} TPM_DEVICE_INFO, *PTPM_DEVICE_INFO;