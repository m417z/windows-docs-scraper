typedef struct _PROCESSOR_POWER_POLICY {
  DWORD                       Revision;
  BYTE                        DynamicThrottle;
  BYTE                        Spare[3];
  DWORD                       DisableCStates : 1;
  DWORD                       Reserved : 31;
  DWORD                       PolicyCount;
  PROCESSOR_POWER_POLICY_INFO Policy[3];
} PROCESSOR_POWER_POLICY, *PPROCESSOR_POWER_POLICY;