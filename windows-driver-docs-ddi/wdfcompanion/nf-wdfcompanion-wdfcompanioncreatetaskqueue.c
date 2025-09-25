NTSTATUS WdfCompanionCreateTaskQueue(
  [in]            WDFCOMPANION           Companion,
  [in]            PWDF_TASK_QUEUE_CONFIG Config,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES QueueAttributes,
  [out, optional] WDFTASKQUEUE           *Queue
);