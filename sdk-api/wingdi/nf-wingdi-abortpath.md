# AbortPath function

## Description

The **AbortPath** function closes and discards any paths in the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context from which a path will be discarded.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If there is an open path bracket in the given device context, the path bracket is closed and the path is discarded. If there is a closed path in the device context, the path is discarded.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)