# CMSPAddress::PostEvent

## Description

The
**PostEvent** method is called by the MSPCall to post an event to TAPI3. This method puts the event at the end of the event list and signals TAPI3. Locks the event list.

## Parameters

### `EventItem` [in]

Pointer to the
[MSPEVENTITEM](https://learn.microsoft.com/windows/desktop/api/mspaddr/ns-mspaddr-mspeventitem) structure, which contains the event information.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)