## Description

Initializes a DirectDraw object that was created by using the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) COM function.

## Parameters

### `unnamedParam1` [in]

A pointer to the globally unique identifier (GUID) that this method uses as the DirectDraw interface identifier.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_ALREADYINITIALIZED
* DDERR_DIRECTDRAWALREADYCREATED
* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NODIRECTDRAWHW
* DDERR_NODIRECTDRAWSUPPORT
* DDERR_OUTOFMEMORY

This method is provided for compliance with the Component Object Model (COM). If you already used the [DirectDrawCreate](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawcreate) function to create a DirectDraw object, this method returns DDERR_ALREADYINITIALIZED. If you do not call **IDirectDraw7::Initialize** when you use [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create a DirectDraw object, any method that you call afterward returns DDERR_NOTINITIALIZED.

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)