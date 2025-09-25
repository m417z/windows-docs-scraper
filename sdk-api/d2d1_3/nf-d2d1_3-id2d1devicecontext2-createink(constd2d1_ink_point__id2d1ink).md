# ID2D1DeviceContext2::CreateInk(const D2D1_INK_POINT &,ID2D1Ink)

## Description

Creates a new [ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink) object that starts at the given point.

## Parameters

### `startPoint` [ref]

Type: **const [D2D1_INK_POINT](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_point)**

The starting point of the first segment of the first stroke in the new ink object.

### `ink` [out]

Type: **[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)****

When this method returns, contains the address of a pointer to a new ink object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)