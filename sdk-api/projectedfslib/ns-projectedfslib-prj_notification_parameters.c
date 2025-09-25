typedef union PRJ_NOTIFICATION_PARAMETERS {
  struct {
    PRJ_NOTIFY_TYPES NotificationMask;
  } PostCreate;
  struct {
    PRJ_NOTIFY_TYPES NotificationMask;
  } FileRenamed;
  struct {
    BOOLEAN IsFileModified;
  } FileDeletedOnHandleClose;
} PRJ_NOTIFICATION_PARAMETERS;