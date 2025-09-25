# IDirectDraw7::GetDeviceIdentifier

## Description

Obtains information about the device driver. This method can be used, with caution, to recognize specific hardware installations to implement workarounds for poor driver or chipset behavior.

## Parameters

### `unnamedParam1` [out]

A pointer to a [DDDEVICEIDENTIFIER2](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-dddeviceidentifier2) structure that receives information about the driver.

### `unnamedParam2` [in]

This value consists of flags that specify options. The following flag is the only defined flag:

#### DDGDI_GETHOSTIDENTIFIER

Causes **GetDeviceIdentifier** to return information about the host (typically 2-D) adapter in a system equipped with a stacked secondary 3-D adapter. Such an adapter appears to the application as if it were part of the host adapter, but is typically located on a separate card. When the *dwFlags* parameter is 0, information on the stacked secondary is returned because this most accurately reflects the qualities of the DirectDraw object involved.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return DDERR_INVALIDPARAMS.

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)