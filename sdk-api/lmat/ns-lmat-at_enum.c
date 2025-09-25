typedef struct _AT_ENUM {
  DWORD     JobId;
  DWORD_PTR JobTime;
  DWORD     DaysOfMonth;
  UCHAR     DaysOfWeek;
  UCHAR     Flags;
  LPWSTR    Command;
} AT_ENUM, *PAT_ENUM, *LPAT_ENUM;