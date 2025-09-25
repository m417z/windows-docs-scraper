# WNDOBJ_vSetConsumer function

## Description

The **WNDOBJ_vSetConsumer** function sets a driver-defined value in the **pvConsumer** field of the specified [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure.

## Parameters

### `pwo`

Pointer to a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure created by a prior call to [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd).

### `pvConsumer`

A driver-defined value for identifying this particular WNDOBJ structure. This value overrides the previous value stored in the WNDOBJ structure.

## Return value

None

## Remarks

**WNDOBJ_vSetConsumer** should be called only by the following functions:

* Graphics DDI functions for which a WNDOBJ structure is provided.
* The callback provided to GDI by a driver's call to **EngCreateWnd**.
* The WNDOBJ_SETUP escape defined by [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape) after a new WNDOBJ structure is created.

## See also

[DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape)

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)