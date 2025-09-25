typedef struct _RIO_NOTIFICATION_COMPLETION {
  RIO_NOTIFICATION_COMPLETION_TYPE Type;
  union {
    struct {
      HANDLE EventHandle;
      BOOL   NotifyReset;
    } Event;
    struct {
      HANDLE IocpHandle;
      PVOID  CompletionKey;
      PVOID  Overlapped;
    } Iocp;
  };
} RIO_NOTIFICATION_COMPLETION, *PRIO_NOTIFICATION_COMPLETION;