# QUERYTABLE structure

The **QUERYTABLE** structure provides a list of the computers that are currently using Network Monitor to capture network data.

## Members

**nStationQueries**

On input, the maximum number of computers you want Network Monitor to return.

On output, the number of [STATIONQUERY](https://learn.microsoft.com/windows/win32/netmon2/stationquery) structures returned by Network Monitor. Each **STATIONQUERY** structure represents a computer that is currently capturing data.

**StationQuery**

On input, an array of empty [STATIONQUERY](https://learn.microsoft.com/windows/win32/netmon2/stationquery) structures that contains the number of elements specified in **nStationQueries**.

On output, a filled [STATIONQUERY](https://learn.microsoft.com/windows/win32/netmon2/stationquery) structure for each computer that is capturing data. The number of filled elements is returned by **nStationQueries**.

## Remarks

The memory for this structure and the [STATIONQUERY](https://learn.microsoft.com/windows/win32/netmon2/stationquery) array must be allocated by the calling application and freed after the information is no longer needed.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[IDelaydC::QueryStations](https://learn.microsoft.com/windows/win32/netmon2/idelaydc-querystations)

[IESP::QueryStations](https://learn.microsoft.com/windows/win32/netmon2/iesp-querystations)

[IRTC::QueryStations](https://learn.microsoft.com/windows/win32/netmon2/irtc-querystations)

[IStats::QueryStations](https://learn.microsoft.com/windows/win32/netmon2/istats-querystations)

[STATIONQUERY](https://learn.microsoft.com/windows/win32/netmon2/stationquery)

