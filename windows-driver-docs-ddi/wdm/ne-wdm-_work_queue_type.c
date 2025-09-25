typedef enum _WORK_QUEUE_TYPE {
  CriticalWorkQueue,
  DelayedWorkQueue,
  HyperCriticalWorkQueue,
  NormalWorkQueue,
  BackgroundWorkQueue,
  RealTimeWorkQueue,
  SuperCriticalWorkQueue,
  MaximumWorkQueue,
  CustomPriorityWorkQueue
} WORK_QUEUE_TYPE;