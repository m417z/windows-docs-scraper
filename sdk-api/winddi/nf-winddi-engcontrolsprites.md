# EngControlSprites function

## Description

The **EngControlSprites** function tears down or redraws sprites on the specified [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) area.

## Parameters

### `pwo`

Pointer to the [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure on which the sprites are being built or torn down.

### `fl`

This parameter can be one of the following values:

#### ECS_TEARDOWN

Requests that GDI tear down and remove the sprite effect of any sprite that overlaps the WNDOBJ area. In other words, GDI redraws the sprite with a neutralized effect so the sprite is not visible on the screen. GDI restores the area beneath the sprite by making immediate calls to [DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits).

#### ECS_REDRAW

Requests that GDI redraw, restoring any sprites that overlap the WNDOBJ area. GDI redraws directly to the screen by making calls to *DrvCopyBits*.

## Return value

**EngControlSprites** returns **TRUE** upon successfully completing the requested operation; otherwise, it returns **FALSE**.

## Remarks

The invocation of ECS_TEARDOWN may be persistent. For example, the driver can call **EngControlSprites** once with ECS_TEARDOWN as soon as it has created the WNDOBJ, and no sprites will ever be drawn on top of the window.

The driver can call **EngControlSprites** with ECS_REDRAW numerous times without making intervening calls with ECS_TEARDOWN in order to force the repainting of a sprite at any time.

ECS_TEARDOWN always forces an immediate redraw of any sprites on top of the WNDOBJ area. GDI saves the bits beneath the sprites by calling [DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits) to copy them from the screen, and then composites the sprites onto the screen by calling *DrvCopyBits*. This can be used to allow sprites to be composited onto a back-buffer just before a swap-buffer command is sent to the hardware (through [DrvSwapBuffers](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvswapbuffers) or any other driver swap buffer mechanism). This permits seamless compositing of sprites, without flashing, when the window is double buffering.

ECS_TEARDOWN will never cause a WOC_SPRITE_NO_OVERLAP message to be sent, and likewise ECS_REDRAW will never cause a WOC_SPRITE_OVERLAP message to be sent.

**EngControlSprites** can be called even if no sprites currently overlap the WNDOBJ area.

## See also

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)