# FlattenPath function

## Description

The **FlattenPath** function transforms any curves in the path that is selected into the current device context (DC), turning each curve into a sequence of lines.

## Parameters

### `hdc` [in]

A handle to a DC that contains a valid path.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[WidenPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-widenpath)