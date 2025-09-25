## Description

The **DdMoCompRender** callback function tells the driver what macroblocks to render by specifying the surfaces containing the macroblocks, the offsets in each surface where the macroblocks exist, and the size of the macroblock data to be rendered.

## Parameters

### `unnamedParam1`

Points to a [DD_RENDERMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_rendermocompdata) structure that contains the information needed to render a frame.

## Return value

**DdMoCompRender** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompRender**.

**DdMoCompRender** can be called multiple times between the [DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe) and [DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe) sequence.

If a previous render operation is not yet finished, the driver should fail the call by setting the **ddRVal** member of the DD_RENDERMOCOMPDATA structure at *lpRenderData* to DDERR_WASSTILLDRAWING and returning DDHAL_DRIVER_HANDLED.

## See also

[DD_RENDERMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_rendermocompdata)

[DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe)

[DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe)