# GetMiterLimit function

## Description

The **GetMiterLimit** function retrieves the miter limit for the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context.

### `plimit` [out]

Pointer to a floating-point value that receives the current miter limit.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The miter limit is used when drawing geometric lines that have miter joins.

## See also

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit)