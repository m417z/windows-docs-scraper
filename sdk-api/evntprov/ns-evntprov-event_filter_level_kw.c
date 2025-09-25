typedef struct _EVENT_FILTER_LEVEL_KW {
  ULONGLONG MatchAnyKeyword;
  ULONGLONG MatchAllKeyword;
  UCHAR     Level;
  BOOLEAN   FilterIn;
} EVENT_FILTER_LEVEL_KW, *PEVENT_FILTER_LEVEL_KW;