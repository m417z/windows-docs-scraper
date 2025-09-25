# IDirectManipulationViewport::Disable

## Description

Stops input processing by the viewport.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a viewport is disabled, it immediately stops all transforms and moves the content to the final location.

Call this method when you want to modify multiple attributes atomically. This method can be called at any time.

The viewport will not resume processing input until [Enable](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-enable) is called.

#### Examples

The following example shows how to use this method.

```
HRESULT hr = pViewport->Disable();
```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)