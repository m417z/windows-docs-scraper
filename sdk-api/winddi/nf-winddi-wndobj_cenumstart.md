# WNDOBJ_cEnumStart function

## Description

The **WNDOBJ_cEnumStart** function is a callback function that sets parameters for enumeration of rectangles in the visible region of a window.

## Parameters

### `pwo`

Pointer to a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure created by a call to [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd).

### `iType`

Specifies the type of structures to be returned by [WNDOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_benum). This parameter can be CT_RECTANGLES, meaning that the region is to be enumerated as a list of rectangles.

### `iDirection`

Determines the order in which the rectangles are returned. This order can be essential when an overlapping [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) is being performed on the same surface. If the order is not relevant to the device driver, then CD_ANY should be specified. This allows GDI to optimize its enumeration for complex regions. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| CD_ANY | Any order convenient for GDI. |
| CD_LEFTDOWN | Right to left, top to bottom. |
| CD_LEFTUP | Right to left, bottom to top. |
| CD_LEFTWARDS | Left to right, vertical direction is not defined. |
| CD_RIGHTDOWN | Left to right, top to bottom. |
| CD_RIGHTUP | Left to right, bottom to top. |
| CD_UPWARDS | Bottom to top, horizontal direction is not defined. |

### `cLimit`

Is an indication of how many objects the driver is interested in caching. This is only used to decide when to stop counting rectangles while GDI is calculating the return value for this function. If *cLimit* is zero, counting is not done.

## Return value

The return value is a count of the number of objects that would be enumerated, provided this value is less than or equal to *cLimit*. If the count is greater than *cLimit*, the return value is 0xFFFFFFFF.

## Remarks

Enumeration can be restarted by calling this function again.

**WNDOBJ_cEnumStart** should be called only:

* In the context of the driver callback function supplied to GDI in the [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd) function, or the graphics DDI functions where a WNDOBJ is given.
* When the calling thread has the device lock to ensure that no client region changes occur.

## See also

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[EngLockDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-englockdriverobj)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)

[WNDOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_benum)