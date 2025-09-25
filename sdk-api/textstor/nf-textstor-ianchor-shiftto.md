# IAnchor::ShiftTo

## Description

The **IAnchor::ShiftTo** method shifts the current anchor to the same position as another anchor.

## Parameters

### `paSite` [in]

Anchor occupying a position that the current anchor will be moved to.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An [IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor) interface pointer to the *paSite* anchor could not be obtained, or memory is too low to safely complete the operation. |
| **E_INVALIDARG** | *paSite* is invalid. |

## Remarks

Implementing this method is usually more efficient than an equivalent [IAnchor::Shift](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-shift) operation.

## See also

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::Shift](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-shift)