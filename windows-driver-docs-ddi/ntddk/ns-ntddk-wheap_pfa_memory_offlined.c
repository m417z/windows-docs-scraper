typedef struct _WHEAP_PFA_MEMORY_OFFLINED {
  WHEA_EVENT_LOG_ENTRY            WheaEventLogEntry;
  WHEAP_PFA_OFFLINE_DECISION_TYPE DecisionType;
  BOOLEAN                         ImmediateSuccess;
  ULONG                           Page;
  BOOLEAN                         NotifyVid;
} WHEAP_PFA_MEMORY_OFFLINED, *PWHEAP_PFA_MEMORY_OFFLINED;