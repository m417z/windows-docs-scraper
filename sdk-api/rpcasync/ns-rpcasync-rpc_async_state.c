typedef struct _RPC_ASYNC_STATE {
  unsigned int                Size;
  unsigned long               Signature;
  long                        Lock;
  unsigned long               Flags;
  void                        *StubInfo;
  void                        *UserInfo;
  void                        *RuntimeInfo;
  RPC_ASYNC_EVENT             Event;
  RPC_NOTIFICATION_TYPES      NotificationType;
  RPC_ASYNC_NOTIFICATION_INFO u;
  LONG_PTR                    Reserved[4];
} RPC_ASYNC_STATE, *PRPC_ASYNC_STATE;