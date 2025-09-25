# SelectClipPath function

## Description

The **SelectClipPath** function selects the current path as a clipping region for a device context, combining the new region with any existing clipping region using the specified mode.

## Parameters

### `hdc` [in]

A handle to the device context of the path.

### `mode` [in]

The way to use the path. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RGN_AND** | The new clipping region includes the intersection (overlapping areas) of the current clipping region and the current path. |
| **RGN_COPY** | The new clipping region is the current path. |
| **RGN_DIFF** | The new clipping region includes the areas of the current clipping region with those of the current path excluded. |
| **RGN_OR** | The new clipping region includes the union (combined areas) of the current clipping region and the current path. |
| **RGN_XOR** | The new clipping region includes the union of the current clipping region and the current path but without the overlapping areas. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The device context identified by the *hdc* parameter must contain a closed path.

#### Examples

For an example, see [Using Clipping](https://learn.microsoft.com/windows/desktop/gdi/using-clipping).

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)