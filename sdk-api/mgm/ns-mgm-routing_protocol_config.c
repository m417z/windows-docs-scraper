typedef struct _ROUTING_PROTOCOL_CONFIG {
  DWORD                        dwCallbackFlags;
  PMGM_RPF_CALLBACK            pfnRpfCallback;
  PMGM_CREATION_ALERT_CALLBACK pfnCreationAlertCallback;
  PMGM_PRUNE_ALERT_CALLBACK    pfnPruneAlertCallback;
  PMGM_JOIN_ALERT_CALLBACK     pfnJoinAlertCallback;
  PMGM_WRONG_IF_CALLBACK       pfnWrongIfCallback;
  PMGM_LOCAL_JOIN_CALLBACK     pfnLocalJoinCallback;
  PMGM_LOCAL_LEAVE_CALLBACK    pfnLocalLeaveCallback;
  PMGM_DISABLE_IGMP_CALLBACK   pfnDisableIgmpCallback;
  PMGM_ENABLE_IGMP_CALLBACK    pfnEnableIgmpCallback;
} ROUTING_PROTOCOL_CONFIG, *PROUTING_PROTOCOL_CONFIG;