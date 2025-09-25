# WNDOBJ_bEnum function

## Description

The **WNDOBJ_bEnum** function obtains a batch of rectangles from the visible region of a window.

## Parameters

### `pwo`

Pointer to a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure created by a call to [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd).

### `cj`

Specifies the size, in bytes, of the buffer pointed to by *pul*. GDI will not write beyond this limit.

### `pul`

Pointer to the buffer in which a structure of the following form is to be written. In this structure, **c** is a count of the rectangles returned, and **arcl** is an array of rectangles:

```
typedef struct _ENUMRECTS{
    ULONG c;
    RECTL arcl[]
} ENUMRECTS;
```

## Return value

The return value is **TRUE** if there is more data to be enumerated and the driver should repeat the call. It is **FALSE** if the enumeration is complete.

## Remarks

The order of enumeration is determined by the call to [WNDOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_cenumstart).

A possible loop structure for calling this function follows.

```
do {
    bMore = WNDOBJ_bEnum(pwo, sizeof(buffer), &buffer.c);
    for (i = 0; i < buffer.c; i++) {
        //  Process the data
    }
} while (bMore);
```

**WNDOBJ_bEnum** should be called only by the callback function provided to GDI by the [EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd) function, or by the graphics DDI functions that are given a WNDOBJ.

## See also

[EngCreateWnd](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatewnd)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)

[WNDOBJ_cEnumStart](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-wndobj_cenumstart)