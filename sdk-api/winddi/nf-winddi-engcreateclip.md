# EngCreateClip function

## Description

The **EngCreateClip** function creates a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that the driver uses in callbacks.

## Return value

The return value is a pointer to the newly-created CLIPOBJ structure if the function succeeds. Otherwise, it is **NULL**.

## Remarks

The CLIPOBJ structure created by **EngCreateClip** allows GDI to directly access banked frame buffers. The structure must be initialized by the driver so that the **iDComplexity** member of the CLIPOBJ structure is set to DC_TRIVIAL or DC_RECT. If the **iDComplexity** member is set to DC_RECT, the driver can set the **rclBounds** member of CLIPOBJ to the extent of the frame buffer bank. The driver must delete this CLIPOBJ structure using [EngDeleteClip](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeleteclip).

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[EngDeleteClip](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeleteclip)