# _BIDI_RESPONSE_CONTAINER structure

## Description

The BIDI_RESPONSE_CONTAINER structure is a container for a list of bidi responses.

## Members

### `Version`

Specifies the version of the bidi API Schema, which is currently 1.

### `Flags`

Is a set of flags reserved for system use. This must be zero.

### `Count`

Specifies the number of responses in the **aData** member.

### `aData`

Is an array of [BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data) structures, each containing a single bidi response.

## Remarks

Even though the **aData** member of this structure is an array with only a single array element, **aData**[0] should be thought of as the first element of an array of (possibly) an arbitrarily large size.

The spooler's [RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer) function allocates the memory needed for this structure, which is then used to hold an array of BIDI_RESPONSE_DATA structures. When a BIDI_RESPONSE_CONTAINER structure is no longer needed, it should be freed by a call to [RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer).

## See also

[BIDI_RESPONSE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_response_data)

[RouterAllocBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerallocbidiresponsecontainer)

[RouterFreeBidiResponseContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidiresponsecontainer)