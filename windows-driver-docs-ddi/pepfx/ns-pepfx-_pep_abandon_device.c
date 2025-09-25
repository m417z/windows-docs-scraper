typedef struct _PEP_ABANDON_DEVICE {
  [in]  PCUNICODE_STRING DeviceId;
  [out] BOOLEAN          DeviceAccepted;
} PEP_ABANDON_DEVICE, *PPEP_ABANDON_DEVICE;