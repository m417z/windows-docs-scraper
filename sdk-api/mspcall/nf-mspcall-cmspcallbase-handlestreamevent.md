# CMSPCallBase::HandleStreamEvent

## Description

The
**HandleStreamEvent** method is called by a stream to send an event to TAPI. It fills in the call handle in the event info structure and then calls the PostEvent method on the MSP address object. (Note that this way, events generated on the streams "flow" toward the address object via the call object, with more information filled in at each step. This reduces the amount of state that must be kept in the MSP call and MSP stream objects.)

## Parameters

### `EventItem`

Pointer to
[MSPEVENTITEM](https://learn.microsoft.com/windows/desktop/api/mspaddr/ns-mspaddr-mspeventitem), a struct containing a linked list of
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) structures.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)