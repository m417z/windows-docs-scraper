# _BIDI_RESPONSE_DATA structure

## Description

The BIDI_RESPONSE_DATA structure holds a single bidi response.

## Members

### `dwResult`

Specifies the last error of the response.

### `dwReqNumber`

Specifies a number used to match a response and a request in a multirequest operation.

### `pSchema`

Pointer to a memory location containing the first byte of the schema string.

### `data`

Specifies a [BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data) structure containing the data associated with the schema.

## Remarks

The spooler's [RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer) function is used to allocate the memory needed for a [BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container) structure, which is then used to hold an array of BIDI_RESPONSE_DATA structures. When a BIDI_RESPONSE_CONTAINER structure is no longer needed, it should be freed by a call to [RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer).

When the bidi action is BIDI_ACTION_GETALL, the **dwReqNumber** member holds the ID of the matching request in the [BIDI_REQUEST_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_container) structure, the **pSchema** member points to the schema string associated with the data, and the **data** member holds the bidi data. If the bidi action is BIDI_ACTION_ENUM_SCHEMA, **pSchema** should be set to **NULL**, and the **data** member will hold the supported schema string. In this case, **data.dwDataType** is set to BIDI_TEXT (a [BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data) enumerator). For information about the BIDI_ACTION_*Xxx* constants, see IBidiSpooler::MultiSendRecv in the Microsoft Windows SDK documentation.

## See also

[BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container)

[RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer)

[RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer)