typedef struct _NDIS_POLL_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                 Header;
  NDIS_SET_POLL_NOTIFICATION_HANDLER SetPollNotificationHandler;
  NDIS_POLL_HANDLER                  PollHandler;
} NDIS_POLL_CHARACTERISTICS;