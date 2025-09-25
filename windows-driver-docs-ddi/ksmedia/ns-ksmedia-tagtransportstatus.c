typedef struct tagTRANSPORTSTATUS {
  LONG Mode;
  LONG LastError;
  LONG RecordInhibit;
  LONG ServoLock;
  LONG MediaPresent;
  LONG MediaLength;
  LONG MediaSize;
  LONG MediaTrackCount;
  LONG MediaTrackLength;
  LONG MediaTrackSide;
  LONG MediaType;
  LONG LinkMode;
  LONG NotifyOn;
} TRANSPORTSTATUS, *PTRANSPORTSTATUS;