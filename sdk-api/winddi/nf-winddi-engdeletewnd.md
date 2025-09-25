# EngDeleteWnd function

## Description

The **EngDeleteWnd** function deletes a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure.

## Parameters

### `pwo`

Pointer to the WNDOBJ structure to be deleted.

## Return value

None

## Remarks

Because deleting a window object involves locking window resources, **EngDeleteWnd** should be called only in the context of the WNDOBJ_SETUP escape in [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape), or from an [MCD](https://learn.microsoft.com/windows-hardware/drivers/) or [ICD](https://learn.microsoft.com/windows-hardware/drivers/) escape.

A driver can call **EngDeleteWnd** to remove its WNDOBJ structure associated with a window regardless of whether the window continues to exist. This is useful when the driver is being dynamically unloaded by the system while the associated window still exists.

## See also

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)