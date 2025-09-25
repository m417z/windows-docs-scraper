# IDirectDrawClipper::Initialize

## Description

Initializes a DirectDrawClipper object that was created by using the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) COM function.

## Parameters

### `unnamedParam1` [in]

A pointer to the DirectDraw object to associate with the DirectDrawClipper object. If this parameter is set to NULL, an independent DirectDrawClipper object is initialized; a call of this type is equivalent to using the [DirectDrawCreateClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawcreateclipper) function.

### `unnamedParam2` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_ALREADYINITIALIZED
* DDERR_INVALIDPARAMS

## Remarks

The **IDirectDrawClipper::Initialize** method is provided for compliance with the Component Object Model (COM). If you used the [DirectDrawCreateClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawcreateclipper) function or the [IDirectDraw7::CreateClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-createclipper) method to create the DirectDrawClipper object, the **IDirectDrawClipper::Initialize** method returns DDERR_ALREADYINITIALIZED.

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)