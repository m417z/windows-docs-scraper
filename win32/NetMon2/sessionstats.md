# SESSIONSTATS structure

The **SESSIONSTATS** structure provides statistics about a [*session*](https://learn.microsoft.com/windows/win32/netmon2/s).

## Members

**NextSession**

Index of the station owner's next session.

**StationOwner**

Index of an owner station within the associated [STATIONSTATS](https://learn.microsoft.com/windows/win32/netmon2/stationstats) structure array. The owner station is the station that initiated the session, the station that sent the packets of the session.

**StationPartner**

Index of the other station within the associated [STATIONSTATS](https://learn.microsoft.com/windows/win32/netmon2/stationstats) structure array. The partner station is the station that received the packets of the session.

**Flags**

This member is obsolete.

**TotalPacketsSent**

Number of packets sent in the session.

## Remarks

Network Monitor stores session and station information in two associated arrays, whose elements are **SESSIONSTATS** and [STATIONSTATS](https://learn.microsoft.com/windows/win32/netmon2/stationstats) structures respectively. The members of these structures can be used to navigate between them. For example, to move to the next session for a specific station owner, use **NextSession**. To jump to the owner and partner station of the session in the STATIONSTATS array, use the index provided in **StationOwner** and **StationPartner**.

> [!Note]
> The SESSIONSTATS array contains an element for each session in the current capture. The algorithm Network Monitor uses to add elements to the SESSIONSTATS array is based on efficiently recording information while the capture is in progress. Consequently, the next session for a specific owner station is not always the next element in the array.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[IDelaydC::GetConversationStatistics](https://learn.microsoft.com/windows/win32/netmon2/idelaydc-getconversationstatistics)

[IRTC::GetConversationStatistics](https://learn.microsoft.com/windows/win32/netmon2/irtc-getconversationstatistics)

[IStats::GetConversationStatistics](https://learn.microsoft.com/windows/win32/netmon2/istats-getconversationstatistics)

