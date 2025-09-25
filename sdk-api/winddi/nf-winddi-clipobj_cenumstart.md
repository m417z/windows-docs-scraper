# CLIPOBJ_cEnumStart function

## Description

The **CLIPOBJ_cEnumStart** function sets parameters for enumerating rectangles in a specified [clip region](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `pco` [in]

Pointer to the [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that defines the clip region to be enumerated.

### `bAll` [in]

Specifies whether the entire region should be enumerated. This parameter is **TRUE** if the whole region should be enumerated. It is **FALSE** if only the parts relevant to the present drawing operation should be enumerated.

A driver that caches clip regions must enumerate the entire region.

### `iType` [in]

Specifies the data structures that are to be written by [CLIPOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_benum). This parameter currently must be CT_RECTANGLES, indicating that the region is to be enumerated as a list of rectangles.

### `iDirection` [in]

Determines the order in which the rectangles are to be enumerated. This order can be essential if a [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) operation is executing concurrently on the same surface. If the order is not relevant to the device driver, CD_ANY should be specified for complex regions, allowing GDI to optimize the enumeration. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| CD_ANY | Any order convenient for GDI. |
| CD_LEFTDOWN | Right to left, top to bottom. |
| CD_LEFTUP | Right to left, bottom to top. |
| CD_RIGHTDOWN | Left to right, top to bottom. |
| CD_RIGHTUP | Left to right, bottom to top. |

### `cLimit` [in]

Specifies the maximum number of rectangles to be enumerated. If this parameter is zero, counting is omitted.

## Return value

The return value is the count of enumerated rectangles. If the count exceeds **cLimit**, the return value is 0xFFFFFFFF.

## Remarks

A region can be enumerated whether this function is called. By default, the driver only enumerates relevant rectangles, starting at the upper left.

The driver can restart enumeration by calling this function again.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[CLIPOBJ_bEnum](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_benum)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)