# GetPolyFillMode function

## Description

The **GetPolyFillMode** function retrieves the current polygon fill mode.

## Parameters

### `hdc` [in]

Handle to the device context.

## Return value

If the function succeeds, the return value specifies the polygon fill mode, which can be one of the following values.

| Value | Meaning |
| --- | --- |
| ALTERNATE | Selects alternate mode (fills area between odd-numbered and even-numbered polygon sides on each scan line). |
| WINDING | Selects winding mode (fills any region with a nonzero winding value). |

If an error occurs, the return value is zero.

## See also

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)