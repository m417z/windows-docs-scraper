typedef struct _PKTMON_EVT_STREAM_METADATA {
  UINT64        PktGroupId;
  UINT16        PktCount;
  UINT16        AppearanceCount;
  UINT16        DirectionName;
  UINT16        PacketType;
  UINT16        ComponentId;
  UINT16        EdgeId;
  UINT16        FilterId;
  UINT32        DropReason;
  UINT32        DropLocation;
  UINT16        ProcNum;
  LARGE_INTEGER TimeStamp;
} PKTMON_EVT_STREAM_METADATA;