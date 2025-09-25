typedef struct _PROCESSOR_POWER_POLICY_INFO {
  DWORD TimeCheck;
  DWORD DemoteLimit;
  DWORD PromoteLimit;
  BYTE  DemotePercent;
  BYTE  PromotePercent;
  BYTE  Spare[2];
  DWORD AllowDemotion : 1;
  DWORD AllowPromotion : 1;
  DWORD Reserved : 30;
} PROCESSOR_POWER_POLICY_INFO, *PPROCESSOR_POWER_POLICY_INFO;