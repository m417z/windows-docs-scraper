# IDirectDrawClipper::GetClipList

## Description

Retrieves a copy of the clip list that is associated with a DirectDrawClipper object. To select a subset of the clip list, you can pass a rectangle that clips the clip list.

## Parameters

### `unnamedParam1` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that **GetClipList** uses to clip the clip list. Set this parameter to NULL to retrieve the entire clip list.

### `unnamedParam2` [out]

A pointer to a [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure that receives the resulting copy of the clip list. If this parameter is NULL, **GetClipList** fills the variable at *lpdwSize* with the number of bytes necessary to hold the entire clip list.

### `unnamedParam3` [out]

A pointer to a variable that receives the size of the resulting clip list. When retrieving the clip list, this parameter is the size of the buffer at *lpClipList*. When *lpClipList* is NULL, the variable at *lpdwSize* receives the required size of the buffer, in bytes.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDCLIPLIST
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOCLIPLIST
* DDERR_REGIONTOOSMALL

## Remarks

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)