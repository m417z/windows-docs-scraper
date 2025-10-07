# STATIONSTATS structure

The **STATIONSTATS** structure provides statistics about a specific [*station*](https://learn.microsoft.com/windows/win32/netmon2/s) described by the current capture.

## Members

**NextStationStats**

Index of the next station recorded in the **STATIONSTATS** structure array.

**SessionPartnerList**

Index of the station partner list.

**Flags**

This member is obsolete.

**StationAddress**

The MAC address of the station.

**Pad**

**DWORD** alignment.

**TotalPacketsReceived**

Total number of packets sent to the station.

**TotalDirectedPacketsSent**

Total number of directed packets sent by the station.

**TotalBroadcastPacketsSent**

Total number of broadcast-directed packets (MAC address FF FF FF FF FF FF) sent by the station.

**TotalMulticastPacketsSent**

Total number of multicast packets (Group bit set in destination address) sent by the station.

**TotalBytesReceived**

Total number of bytes sent to the station.

**TotalBytesSent**

Total number of bytes sent by the station.

## Remarks

Network Monitor stores session and station information in two associated arrays. whose elements are [SESSIONSTATS](https://learn.microsoft.com/windows/win32/netmon2/sessionstats) and **STATIONSTATS** structures respectively. The members of these structures can be used to navigate between them. For example, to move to the next station use **NextStationStats**. To jump to the session partner list in the SESSIONSTATS array, use the index provided in **SessionPartnerList**.

> [!Note]
> The **STATIONSTATS** array contains an element for each station used during the current capture. The algorithm Network Monitor uses to add elements to this array is based on the most efficient way to record information while the capture is in progress. Consequently, the next station is not always the next element in the array.

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

