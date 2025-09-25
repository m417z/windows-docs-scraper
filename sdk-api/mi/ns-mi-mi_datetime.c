typedef struct _MI_Datetime {
  MI_Uint32 isTimestamp;
  union {
    MI_Timestamp timestamp;
    MI_Interval  interval;
  } u;
} MI_Datetime;