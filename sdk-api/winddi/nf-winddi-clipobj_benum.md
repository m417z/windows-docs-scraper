# CLIPOBJ_bEnum function

## Description

The **CLIPOBJ_bEnum** function enumerates a batch of rectangles from a specified [clip region](https://learn.microsoft.com/windows-hardware/drivers/); a prior call to [CLIPOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_cenumstart) determines the order of enumeration.

## Parameters

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure describing the clip region that is to be enumerated.

### `cj` [in]

Specifies the size, in bytes, of the buffer pointed to by *pv*.

### `pul` [out]

Pointer to the buffer that will receive data about the clip region in an [ENUMRECTS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-enumrects) structure.

## Return value

The return value is **TRUE** if the driver must call this function again for more enumeration data, or **FALSE** if the enumeration is complete. It is possible for **CLIPOBJ_bEnum** to return **TRUE** with the number of clipping rectangles equal to zero. In such cases, the driver should call **CLIPOBJ_bEnum** again without taking any action.

## Remarks

A possible loop structure for calling this function follows:

```
do {
    bMore = CLIPOBJ_bEnum(pco, sizeof(buffer), &buffer.c);
    for (i = 0; i < buffer.c; i++) {
        .
        .
        .
    }
} while (bMore);
```

The count of objects written to the buffer is written to the buffer itself.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[CLIPOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-clipobj_cenumstart)

[ENUMRECTS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-enumrects)