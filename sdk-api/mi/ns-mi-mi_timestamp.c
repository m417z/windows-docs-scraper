typedef struct _MI_Timestamp {
  MI_Uint32 year;
  MI_Uint32 month;
  MI_Uint32 day;
  MI_Uint32 hour;
  MI_Uint32 minute;
  MI_Uint32 second;
  MI_Uint32 microseconds;
  MI_Sint32 utc;
} MI_Timestamp;