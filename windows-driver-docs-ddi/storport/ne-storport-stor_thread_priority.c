typedef enum _STOR_THREAD_PRIORITY {
  StorThreadPriorityBackground,
  StorThreadPriorityNormal,
  StorThreadPriorityDelayed,
  StorThreadPriorityCritical,
  StorThreadPrioritySuperCritical,
  StorThreadPriorityHyperCritical,
  StorThreadPriorityRealTime
} STOR_THREAD_PRIORITY, *PSTOR_THREAD_PRIORITY;