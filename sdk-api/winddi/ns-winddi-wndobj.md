# WNDOBJ structure

## Description

The WNDOBJ structure allows the driver to keep track of the position, size, and visible client region changes of a window.

## Members

### `coClient`

Specifies a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that describes the client region of the window. If **iDComplexity** is DC_RECT and the left edge in **rclBounds** is greater than or equal to the right edge, or the top edge is greater than or equal to the bottom edge, the client region is invisible.

### `pvConsumer`

Pointer to a driver-defined value that identifies this particular WNDOBJ structure. This value can be set by calling the [WNDOBJ_vSetConsumer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_vsetconsumer) function.

### `rclClient`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that describes the client area of the window in screen coordinates. This rectangle is lower-right exclusive, which means that the lower and right-hand edges of this region are not included.

### `psoOwner`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that was passed to [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd) when this WNDOBJ was created.

## Remarks

The visible client region can be enumerated by calling the [WNDOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_cenumstart) and [WNDOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_benum) functions.

A driver can associate its own data with a WNDOBJ by calling the **WNDOBJ_vSetConsumer** function.

As an accelerator, the driver can access public members of the WNDOBJ. These public members are guaranteed to remain unchanged only in the context of the driver callback routine supplied to GDI in the [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd) function, or the functions where a WNDOBJ is given.

The driver should use the SURFOBJ to which **psoOwner** points to retrieve driver-specific state relevant to the WNDOBJ, such as the driver's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) handle, rather than maintain global variables.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[WNDOBJCHANGEPROC](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570601(v=vs.85))

[WNDOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_benum)

[WNDOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_cenumstart)

[WNDOBJ_vSetConsumer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_vsetconsumer)