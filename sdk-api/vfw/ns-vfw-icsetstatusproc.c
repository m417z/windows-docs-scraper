typedef struct {
  DWORD  dwFlags;
  LPARAM lParam;
  LONG( )(LPARAM lParam,UINT message,LONG l)  *Status;
} ICSETSTATUSPROC;