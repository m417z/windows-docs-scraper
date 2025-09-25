# DD_HALINFO structure

## Description

The DD_HALINFO structure describes the capabilities of the hardware and driver.

## Members

### `dwSize`

Specifies the size in bytes of this DD_HALINFO structure.

### `vmiData`

Specifies a [VIDEOMEMORYINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemoryinfo) structure that describes the display's memory.

### `ddCaps`

Specifies a **DDNTCORECAPS** structure that contains driver-specific capabilities.

### `GetDriverInfo`

Points to the driver's [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function. This function is called to get further Microsoft DirectDraw driver information. This member can be **NULL**.

### `dwFlags`

Specifies the display driver's creation flags. This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDHALINFO_ISPRIMARYDISPLAY | The driver is the primary display driver. |
| DDHALINFO_MODEXILLEGAL | This hardware does not support ModeX modes. |
| DDHALINFO_GETDRIVERINFOSET | The **GetDriverInfo** member is set. |
| DDHALINFO_GETDRIVERINFO2 | Driver supports **GetDriverInfo2** variant of **GetDriverInfo**. |

### `lpD3DGlobalDriverData`

Points to a [D3DHAL_GLOBALDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata) structure that describes the 3D capabilities of the driver and its device.

### `lpD3DHALCallbacks`

Points to the driver's initialized [D3DHAL_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_callbacks) structure.

### `lpD3DBufCallbacks`

Used only by drivers that want to implement driver level vertex and command buffer allocation. This is usually done for performance reasons. The **lpD3DBufCallbacks** member is a pointer to a [DD_D3DBUFCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_d3dbufcallbacks) structure that the driver fills out with the callbacks used to support driver managed vertex and command buffers. This member should normally be ignored by the driver.

## Remarks

GDI allocates and zero-initializes the DD_HALINFO structure and passes it to the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) routine to be initialized with driver-specific data.

## See also

[D3DHAL_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_callbacks)

[D3DHAL_GLOBALDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata)

[DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps)

[DD_D3DBUFCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_d3dbufcallbacks)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)

[VIDEOMEMORYINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemoryinfo)