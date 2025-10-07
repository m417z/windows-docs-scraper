TdhGetAllEventsInformation(
    __in PEVENT_RECORD pEvent,
    __in_opt PVOID pWbemService,
    __out ULONG *pIndex,
    __out ULONG *pCount,
    __out_bcount_opt(*pBufferSize) PTRACE_EVENT_INFO *ppBuffer,
    __inout ULONG *pBufferSize
    );