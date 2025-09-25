# WidenPath function

## Description

The **WidenPath** function redefines the current path as the area that would be painted if the path were stroked using the pen currently selected into the given device context.

## Parameters

### `hdc` [in]

A handle to a device context that contains a closed path.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **WidenPath** function is successful only if the current pen is a geometric pen created by the [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) function, or if the pen is created with the [CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen) function and has a width, in device units, of more than one.

The device context identified by the *hdc* parameter must contain a closed path.

Any Bézier curves in the path are converted to sequences of straight lines approximating the widened curves. As such, no Bézier curves remain in the path after **WidenPath** is called.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmiterlimit)