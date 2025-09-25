## Description

**RouterAllocBidiResponseContainer** allocates a [BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container) structure containing a list of bidi responses. The bidi response list is an array of [BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data) structures.

## Parameters

### `Count`

Specifies the number of BIDI_RESPONSE_DATA structures to be allocated.

## Return value

**RouterAllocBidiResponseContainer** returns a pointer to the allocated structure, on success. If the function fails to allocate the structure, the caller can obtain the error code from **GetLastError**.

## Remarks

When the memory allocated by this function is no longer needed, use [RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer).

## See also

[BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container)

[BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data)

[RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer)

[SendRecvBidiDataFromPort](https://learn.microsoft.com/previous-versions/ff562071(v=vs.85))