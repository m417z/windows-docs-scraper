typedef struct _SCHEDULE {
  ULONG           Size;
  ULONG           Bandwidth;
  ULONG           NumberOfSchedules;
  SCHEDULE_HEADER Schedules[1];
} SCHEDULE, *PSCHEDULE;