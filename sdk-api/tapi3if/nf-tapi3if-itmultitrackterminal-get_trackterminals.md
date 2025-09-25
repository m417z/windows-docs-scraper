# ITMultiTrackTerminal::get_TrackTerminals

## Description

The
**get_TrackTerminals** method creates and returns a collection containing the terminals contained by the multitrack terminal on which this method was called. The variant returned contains a pointer to an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) interface that can be used to iterate through elements of type
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant). The elements of the collection contain pointers to tracks.

## Parameters

### `pVariant` [out]

Pointer to a VARIANT containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface pointers for the tracks available.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | The *pVariant* parameter was not empty. |

## Remarks

TAPI calls the **AddRef** method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITMultiTrackTerminal::get_TrackTerminals**. The application must call **Release** on the
**ITTerminal** interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)