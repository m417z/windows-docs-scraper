# IDirectManipulationViewport::GetStatus

## Description

Gets the state of the viewport.

## Parameters

### `status` [out, retval]

One of the values from [DIRECTMANIPULATION_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_status).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the viewport state at the time of the call and not at the time when the return value is read.

This method will fail if called after [Abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-abandon).

#### Examples

The following example shows how to use this method.

```
DIRECTMANIPULATION_STATUS status;

HRESULT hr = pViewport->GetStatus(&status);

```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)