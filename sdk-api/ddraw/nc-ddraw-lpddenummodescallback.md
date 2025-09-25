## Description

Do not use. This callback function is superseded by the [EnumModesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenummodescallback2) function that is used with the [IDirectDraw7::EnumDisplayModes](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-enumdisplaymodes) method.

## Parameters

### `unnamedParam1` [in]

A pointer to a read-only [DDSURFACEDESC](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure that provides the monitor frequency and the mode that can be created.

### `unnamedParam2` [in]

A pointer to an application-defined structure to be passed to the callback function each time that the function is called.

## Return value

The callback function returns DDENUMRET_OK to continue the enumeration.

It returns DDENUMRET_CANCEL to stop the enumeration.

## Remarks

You can use the LPDDENUMMODESCALLBACK data type to declare a variable that can contain a pointer to this callback function.