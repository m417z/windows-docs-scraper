# DirectDrawCreateEx function

## Description

Creates an instance of a DirectDraw object that supports the set of Direct3D interfaces in DirectX 7.0. To use the features of Direct3D in DirectX 7.0, create a DirectDraw object with this function.

## Parameters

### `lpGuid` [in]

A pointer to the globally unique identifier (GUID) that represents the driver to be created. This can be NULL to indicate the active display driver, or you can pass one of the following flags to restrict the active display driver's behavior for debugging purposes:

#### DDCREATE_EMULATIONONLY

The DirectDraw object uses emulation for all features; it does not take advantage of any hardware-supported features.

#### DDCREATE_HARDWAREONLY

The DirectDraw object never emulates features not supported by the hardware. Attempts to call methods that require unsupported features fail, returning DDERR_UNSUPPORTED.

### `lplpDD` [out]

A pointer to a variable to be set to a valid [IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7) interface pointer if the call succeeds.

### `iid` [in]

This parameter must be set to IID_IDirectDraw7. This function fails and returns DDERR_INVALIDPARAMS if any other interface is specified.

### `pUnkOuter` [in]

Allows for future compatibility with COM aggregation features. Currently, this function returns an error if this parameter is not NULL.

## Return value

If the function succeeds, the return value is DD_OK.

If it fails, the function can return one of the following error values:

* DDERR_DIRECTDRAWALREADYCREATED
* DDERR_GENERIC
* DDERR_INVALIDDIRECTDRAWGUID
* DDERR_INVALIDPARAMS
* DDERR_NODIRECTDRAWHW
* DDERR_OUTOFMEMORY

## Remarks

This function attempts to initialize a DirectDraw object, and then sets a pointer to the object if the call succeeds.

On computers with multiple monitors, if you specify NULL for *lpGUID*, the DirectDraw object runs in emulation mode when the normal cooperative level is set. To make use of hardware acceleration on these computers, specify the device's GUID.

You must use [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) to explicitly link to Ddraw.dll and then use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access the **DirectDrawCreateEx** function.