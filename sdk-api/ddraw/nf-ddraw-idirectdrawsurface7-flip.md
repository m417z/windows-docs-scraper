# IDirectDrawSurface7::Flip

## Description

Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.

## Parameters

### `unnamedParam1` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for an arbitrary surface in the flipping chain. The default for this parameter is NULL, in which case DirectDraw cycles through the buffers in the order that they are attached to each other. If this parameter is not NULL, DirectDraw flips to the specified surface, instead of the next surface in the flipping chain. **Flip** fails if the specified surface is not a member of the flipping chain.

### `unnamedParam2` [in]

A combination of flags that specify flip options. The following flags are defined:

#### DDFLIP_DONOTWAIT

On [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interfaces, the default is DDFLIP_WAIT. If you want to override the default and use time when the accelerator is busy (as denoted by the DDERR_WASSTILLDRAWING return value), use DDFLIP_DONOTWAIT.

#### DDFLIP_EVEN

For use only when displaying video in an overlay surface. The new surface contains data from the even field of a video signal. This flag cannot be used with the DDFLIP_ODD flag.

#### DDFLIP_STEREO

DirectDraw flips and displays a main stereo surface. When this flag is set, stereo autoflipping is enabled. The hardware automatically flips between the left and right buffers during each screen refresh.

#### DDFLIP_INTERVAL2

#### DDFLIP_INTERVAL3

#### DDFLIP_INTERVAL4

The DDFLIP_INTERVAL2, DDFLIP_INTERVAL3, and DDFLIP_INTERVAL4 flags indicate how many vertical retraces to wait between each flip. The default is 1. DirectDraw returns DERR_WASSTILLDRAWING for each surface involved in the flip until the specified number of vertical retraces has occurred. If DDFLIP_INTERVAL2 is set, DirectDraw flips on every second vertical sync; if DDFLIP_INTERVAL3, on every third sync; and if DDFLIP_INTERVAL4, on every fourth sync.

These flags are effective only if DDCAPS2_FLIPINTERVAL bit is set in the **dwCaps2** member of the [DDCAPS](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) structure that is returned for the display hardware.

#### DDFLIP_NOVSYNC

Causes DirectDraw to perform the physical flip as close as possible to the next scan line. Subsequent operations that involve the two flipped surfaces do not check whether the physical flip has finished—that is, they do not return DDERR_WASSTILLDRAWING for that reason (but might for other reasons). This allows an application to perform flips at a higher frequency than the monitor refresh rate, but might introduce visible artifacts.

If DDCAPS2_FLIPNOVSYNC is not set in the **dwCaps2** member of the [DDCAPS](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) structure that is returned for the display hardware, DDFLIP_NOVSYNC has no effect.

#### DDFLIP_ODD

For use only when displaying video in an overlay surface. The new surface contains data from the odd field of a video signal. This flag cannot be used with the DDFLIP_EVEN flag.

#### DDFLIP_WAIT

Typically, if the flip cannot be set up because the state of the display hardware is not appropriate, the DDERR_WASSTILLDRAWING error returns immediately, and no flip occurs. Setting this flag causes **Flip** to continue trying to flip if it receives the DDERR_WASSTILLDRAWING error from the hardware abstraction layer (HAL). **Flip** does not return until the flipping operation has been successfully set up or another error, such as DDERR_SURFACEBUSY, is returned.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOFLIPHW
* DDERR_NOTFLIPPABLE
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

With [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7), the default behavior of **Flip** is to wait for the accelerator to finish. Therefore, under default conditions, **Flip** never returns DDERR_WASSTILLDRAWING. If you want to see the error codes and not wait until the flip operation succeeds, use the DDFLIP_DONOTWAIT flag.

**Flip** can be called only for a surface that has the DDSCAPS_FLIP and DDSCAPS_FRONTBUFFER capabilities. The display memory previously associated with the front buffer is associated with the back buffer.

The *lpDDSurfaceTargetOverride* parameter is used in rare cases in which the back buffer is not the buffer that should become the front buffer. Typically, this parameter is NULL.

**Flip** is always synchronized with the vertical blank. If the surface has been assigned to a video port, this method updates the visible overlay surface and the target surface of the video port.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)