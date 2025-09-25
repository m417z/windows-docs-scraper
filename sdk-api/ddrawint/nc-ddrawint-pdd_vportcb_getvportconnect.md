## Description

The *DdVideoPortGetConnectInfo* callback function returns the connections supported by the specified VPE object.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTCONNECTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportconnectdata) structure that contains the information required for the driver to return the VPE object connection data.

## Return value

*DdVideoPortGetConnectInfo* returns one of the following callback codes:

## Remarks

*DdVideoPortGetConnectInfo* must be implemented in DirectDraw drivers that support VPE.

DirectDraw calls *DdVideoPortGetConnectInfo* to obtain the number of connections supported by the specified VPE object and the characteristics of each connection. *DdVideoPortGetConnectInfo* is called twice for the specified VPE object:

* In the first call, the **lpConnect** member of the DD_GETVPORTCONNECTDATA structure at *lpGetConnect* is **NULL**. The driver should write the number of connections that the VPE object supports in the **dwNumEntries** member of DD_GETVPORTCONNECTDATA. Upon return, DirectDraw will allocate this number of DDVIDEOPORTCONNECT structures to pass in the second call to *DdVideoPortGetConnectInfo*.
* In the second call, **lpConnect** points to the array of allocated [DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect) structures. The driver should fill in each structure to describe each connection that the VPE object supports. The driver should also return the number of supported connections in **dwNumEntries**. Note that the driver is guaranteed that the buffer to which **lpConnect** points is large enough to hold the connection information being requested.

## See also

[DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect)

[DD_GETVPORTCONNECTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportconnectdata)