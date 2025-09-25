# IAnchor::GetGravity

## Description

The **IAnchor::GetGravity** method retrieves the gravity of the anchor in an [IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor) object.

## Parameters

### `pgravity` [out]

Pointer that receives a [TsGravity](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsgravity) value that specifies the anchor gravity.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *pgravity* pointer is invalid. |

## See also

[Anchor Gravity](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::SetGravity](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-setgravity)

[TsGravity](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsgravity)