typedef struct _PEP_PREPARE_DEVICE {
  [in]  PCUNICODE_STRING DeviceId;
  [out] BOOLEAN          DeviceAccepted;
} PEP_PREPARE_DEVICE, *PPEP_PREPARE_DEVICE;