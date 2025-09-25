## Description

Retrieves the capabilities of this surface. These capabilities are not necessarily related to the capabilities of the display device.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure that receives the hardware capabilities of this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

The **IDirectDrawSurface7::GetCaps** method differs from its counterpart in the **IDirectDrawSurface3** interface in that it accepts a pointer to a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure, rather than the legacy [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)