NTSTATUS FLTAPI FltApplyPriorityInfoThread(
  [in]            PIO_PRIORITY_INFO InputPriorityInfo,
  [out, optional] PIO_PRIORITY_INFO OutputPriorityInfo,
  [in]            PETHREAD          Thread
);