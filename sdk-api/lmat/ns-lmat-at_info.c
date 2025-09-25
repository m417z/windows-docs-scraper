typedef struct _AT_INFO {
  DWORD_PTR JobTime;
  DWORD     DaysOfMonth;
  UCHAR     DaysOfWeek;
  UCHAR     Flags;
  LPWSTR    Command;
} AT_INFO, *PAT_INFO, *LPAT_INFO;