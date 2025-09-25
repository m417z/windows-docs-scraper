typedef struct _TASK_TRIGGER {
  WORD               cbTriggerSize;
  WORD               Reserved1;
  WORD               wBeginYear;
  WORD               wBeginMonth;
  WORD               wBeginDay;
  WORD               wEndYear;
  WORD               wEndMonth;
  WORD               wEndDay;
  WORD               wStartHour;
  WORD               wStartMinute;
  DWORD              MinutesDuration;
  DWORD              MinutesInterval;
  DWORD              rgFlags;
  TASK_TRIGGER_TYPE  TriggerType;
  TRIGGER_TYPE_UNION Type;
  WORD               Reserved2;
  WORD               wRandomMinutesInterval;
} TASK_TRIGGER, *PTASK_TRIGGER;