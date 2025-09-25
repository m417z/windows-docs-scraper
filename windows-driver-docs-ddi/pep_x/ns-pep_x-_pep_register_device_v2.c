typedef struct _PEP_REGISTER_DEVICE_V2 {
  [in]  PCUNICODE_STRING           DeviceId;
  [in]  POHANDLE                   KernelHandle;
  [in]  PPEP_DEVICE_REGISTER_V2    Register;
  [out] PEPHANDLE                  DeviceHandle;
  [out] PEP_DEVICE_ACCEPTANCE_TYPE DeviceAccepted;
} PEP_REGISTER_DEVICE_V2, *PPEP_REGISTER_DEVICE_V2;