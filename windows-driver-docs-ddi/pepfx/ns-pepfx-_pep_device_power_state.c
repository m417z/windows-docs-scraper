typedef struct _PEP_DEVICE_POWER_STATE {
  [in] PEPHANDLE          DeviceHandle;
  [in] DEVICE_POWER_STATE PowerState;
  [in] BOOLEAN            Complete;
  [in] BOOLEAN            SystemTransition;
} PEP_DEVICE_POWER_STATE, *PPEP_DEVICE_POWER_STATE;