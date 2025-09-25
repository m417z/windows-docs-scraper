# SetMiterLimit function

## Description

The **SetMiterLimit** function sets the limit for the length of miter joins for the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context.

### `limit` [in]

Specifies the new miter limit for the device context.

### `old` [out]

Pointer to a floating-point value that receives the previous miter limit. If this parameter is **NULL**, the previous miter limit is not returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The miter length is defined as the distance from the intersection of the line walls on the inside of the join to the intersection of the line walls on the outside of the join. The miter limit is the maximum allowed ratio of the miter length to the line width.

The default miter limit is 10.0.

**Note** Setting *eNewLimit* to a float value less than 1.0f will cause the function to fail.

## See also

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmiterlimit)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)