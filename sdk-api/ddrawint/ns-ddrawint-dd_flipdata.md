# DD_FLIPDATA structure

## Description

The DD_FLIPDATA structure contains information needed to do a flip.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpSurfCurr`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure describing the current surface.

### `lpSurfTarg`

Points to the DD_SURFACE_LOCAL structure describing the target surface; that is, the surface to which the driver should flip.

### `dwFlags`

Indicates a set of flags that provide the driver with details for the flip. This member can be a bitwise OR of the following flags:

| Flag | Meaning |
| --- | --- |
| DDFLIP_DONOTWAIT | Specifies to return DDERR_WASSTILLDRAWING if the accelerator is busy. The default is DDFLIP_WAIT. |
| DDFLIP_EVEN | The surface to which the **lpSurfTarg** member points contains only the even field of video data. This flag is valid only when the surface is an overlay, and is mutually exclusive of DDFLIP_ODD. |
| DDFLIP_ODD | The surface to which the **lpSurfTarg** member points contains only the odd field of video data. This flag is valid only when the surface is an overlay, and is mutually exclusive of DDFLIP_EVEN. |
| DDFLIP_NOVSYNC | The driver should perform the flip and return immediately. Typically, the current back buffer (which used to be the front buffer) is still visible until the next vertical retrace. Subsequent operations involving the surfaces to which the **lpSurfCurr** and **lpSurfTarg** members point do not check to see if the physical flip has finished. This allows an application to perform flips at a higher frequency than the monitor refresh rate, although it might introduce visible artifacts. |
| DDFLIP_INTERVAL2 | The driver should perform the flip on every other vertical sync. It should return DDERR_WASSTILLDRAWING until the second vertical retrace has occurred. This flag is mutually exclusive of DDFLIP_INTERVAL3 and DDFLIP_INTERVAL4. |
| DDFLIP_INTERVAL3 | The driver should perform the flip on every third vertical sync. It should return DDERR_WASSTILLDRAWING until the third vertical retrace has occurred. This flag is mutually exclusive of DDFLIP_INTERVAL2 and DDFLIP_INTERVAL4. |
| DDFLIP_INTERVAL4 | The driver should perform the flip on every fourth vertical sync. It should return DDERR_WASSTILLDRAWING until the fourth vertical retrace has occurred. This flag is mutually exclusive of DDFLIP_INTERVAL2 and DDFLIP_INTERVAL3. |
| DDFLIP_STEREO | Specifies to enable stereo autoflipping (the hardware automatically flips between the left and right buffers during each screen refresh). |
| DDFLIP_WAIT | Specifies to not return until the flip or an error occurs. |

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `Flip`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

### `lpSurfCurrLeft`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure describing the current left surface.

### `lpSurfTargLeft`

Points to the DD_SURFACE_LOCAL structure describing the left target surface to flip to.

## See also

[DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip)