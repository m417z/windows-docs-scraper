# IDirectManipulationViewport::Enable

## Description

Starts or resumes input processing by the viewport.

## Return value

If the method succeeds, it returns **S_OK**, or **S_FALSE** if there is no work to do (for example, the viewport is already enabled). Otherwise, it returns an **HRESULT** error code.

## Remarks

This method directs a viewport to attempt to respond to input.

Call this method if the **AUTODISABLE** option is set.

#### Examples

The following example shows how to use this method.

```
HRESULT hr = pViewport->Enable();
```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)