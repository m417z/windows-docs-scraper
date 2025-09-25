typedef struct _GLOBAL_MACHINE_POWER_POLICY {
  ULONG              Revision;
  SYSTEM_POWER_STATE LidOpenWakeAc;
  SYSTEM_POWER_STATE LidOpenWakeDc;
  ULONG              BroadcastCapacityResolution;
} GLOBAL_MACHINE_POWER_POLICY, *PGLOBAL_MACHINE_POWER_POLICY;