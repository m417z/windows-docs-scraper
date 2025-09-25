# IInputObjectSite::OnFocusChangeIS

## Description

Informs the browser that the focus has changed.

## Parameters

### `punkObj`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object gaining or losing the focus.

### `fSetFocus`

Type: **BOOL**

Indicates if the object has gained or lost the focus. If this value is nonzero, the object has gained the focus. If this value is zero, the object has lost the focus.

## Return value

Type: **HRESULT**

Returns S_OK if the method was successful, or a COM-defined error code otherwise.

## Remarks

The calling object should call this method whenever one of its windows gains or loses the input focus.