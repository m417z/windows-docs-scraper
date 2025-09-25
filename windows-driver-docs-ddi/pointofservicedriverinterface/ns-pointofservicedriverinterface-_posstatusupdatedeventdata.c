typedef struct _PosStatusUpdatedEventData {
  PosEventDataHeader Header;
  UINT32             Status;
  UINT32             ExtendedStatus;
} PosStatusUpdatedEventData;