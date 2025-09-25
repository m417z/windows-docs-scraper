# TcEnumerateFlows function

## Description

The
**TcEnumerateFlows** function enumerates installed flows and their associated filters on an interface.

The process of returning flow enumeration often consists of multiple calls to the
**TcEnumerateFlows** function. The process of receiving flow information from
**TcEnumerateFlows** can be compared to reading through a book in multiple sittings, where a certain number of pages are read at one time, a bookmark is placed where reading stops, reading is resumed at the bookmark, and continues until the book is finished.

The
**TcEnumerateFlows** function fills the *Buffer* parameter with as many flow enumerations as the buffer can hold, then returns a handle in the pEnumToken parameter that internally bookmarks where the enumeration stopped. Subsequent calls to
**TcEnumerateFlows** must then pass the returned *pEnumToken* value to instruct traffic control where to resume flow enumeration information. When all flows have been enumerated, *pEnumToken* will be **NULL**.

## Parameters

### `IfcHandle` [in]

Handle associated with the interface on which flows are to be enumerated. This handle is obtained by a previous call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function.

### `pEnumHandle` [in, out]

Pointer to the enumeration token, used internally by traffic control to maintain returned flow information state.

For input of the initial call to
**TcEnumerateFlows**, *pEnumToken* should be set to **NULL**. For input on subsequent calls, *pEnumToken* must be the value returned as the *pEnumToken* OUT parameter from the immediately preceding call to
**TcEnumerateFlows**.

For output, *pEnumToken* is the refreshed enumeration token that must be used in the following call to
**TcEnumerateFlows**.

### `pFlowCount` [in, out]

Pointer to the number of requested or returned flows. For input, this parameter designates the number of requested flows or it can be set to **0xFFFF** to request all flows. For output, *pFlowCount* returns the number of flows actually returned in *Buffer*.

### `pBufSize` [in, out]

Pointer to the size of the client-provided buffer or the number of bytes used by traffic control. For input, points to the size of *Buffer*, in bytes. For output, points to the actual amount of buffer space, in bytes, written or needed with flow enumerations.

### `Buffer` [out]

Pointer to the buffer containing flow enumerations. See
[ENUMERATION_BUFFER](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-enumeration_buffer) for more information about flow enumerations.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | Invalid interface handle. |
| **ERROR_INVALID_PARAMETER** | One of the pointers is **NULL**, or *pFlowCount* or *pBufSize* are set to zero. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is too small to store even a single flow's information and attached filters. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_INVALID_DATA** | The enumeration token is no longer valid. |

## Remarks

Do not request zero flows, or pass a buffer with a size equal to zero or pointer to a **NULL**.

If an enumeration token pointer has been invalidated by traffic control (due to the deletion of a flow), continuing to enumerate flows is not allowed, and the call will return ERROR_INVALID_DATA. Under this circumstance, the process of enumeration must start over. This circumstance can occur when the next flow to be enumerated is deleted while enumeration is in progress.

To get the total number of flows for a given interface, call
[TcQueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcqueryinterface) and specify **GUID_QOS_FLOW_COUNT**.

**Note** Use of the
**TcEnumerateFlows** function requires administrative privilege.

## See also

[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea)

[TcQueryInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcqueryinterface)