typedef struct PRJ_COMPLETE_COMMAND_EXTENDED_PARAMETERS {
  PRJ_COMPLETE_COMMAND_TYPE CommandType;
  union {
    struct {
      PRJ_NOTIFY_TYPES NotificationMask;
    } Notification;
    struct {
      PRJ_DIR_ENTRY_BUFFER_HANDLE DirEntryBufferHandle;
    } Enumeration;
  } DUMMYUNIONNAME;
} PRJ_COMPLETE_COMMAND_EXTENDED_PARAMETERS;