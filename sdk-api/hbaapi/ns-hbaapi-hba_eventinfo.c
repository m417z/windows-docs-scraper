typedef struct HBA_EventInfo {
  HBA_UINT32 EventCode;
  union {
    HBA_LINK_EVENTINFO Link_EventInfo;
    HBA_RSCN_EVENTINFO RSCN_EventInfo;
    HBA_PTY_EVENTINFO  Pty_EventInfo;
  } Event;
} HBA_EVENTINFO, *PHBA_EVENTINFO;