# IDirectManipulationViewport2::AddBehavior

## Description

Adds a behavior to the viewport and returns a cookie to the caller.

## Parameters

### `behavior` [in]

A behavior created using the [CreateBehavior](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationmanager2-createbehavior) method.

### `cookie` [out, retval]

A cookie is returned so the caller can remove this behavior later. This allows the caller to release any reference on the behavior and let [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) maintain an appropriate lifetime, similar to event handlers.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. Attaching a behavior that is already attached to this viewport or another viewport results in a failure.

## Remarks

A behavior takes effect immediately after **AddBehavior** is called. This must be considered when adding a behavior during an active manipulation or inertia phase.

## See also

[IDirectManipulationViewport2](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport2)