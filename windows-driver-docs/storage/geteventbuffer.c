void GetEventBuffer(
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS         HBAStatus,
   [out] uint32                                    EventCount,
   [out, WmiSizeIs("EventCount")] MSFC_EventBuffer Events[]
);