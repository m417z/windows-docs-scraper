# RouterFreeBidiResponseContainer function

## Description

`RouterFreeBidiResponseContainer` frees a [BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container) structure previously allocated by [RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer).

## Parameters

### `pData` [in]

Pointer to the BIDI_RESPONSE_CONTAINER structure to be freed.

## Return value

`RouterFreeBidiResponseContainer` normally returns ERROR_SUCCESS, unless it throws an exception. In that case it returns an appropriate error code.

## See also

[BIDI_RESPONSE_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_container)

[RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer)