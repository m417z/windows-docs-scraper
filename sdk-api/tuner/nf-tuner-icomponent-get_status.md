# IComponent::get_Status

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Status** method retrieves the requested or actual status of the component.

## Parameters

### `Status` [out]

Pointer to a [ComponentStatus](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/componentstatus) enumeration that receives the status value.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

When the TIF adds a component to the [IComponents](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents) collection, it can indicate whether the component is active or not. An application can attempt to set this status, and resubmit a tune request. The tuner will update the status from the enumeration: Active, Inactive, Unavailable. The Unavailable status is only set by a tuner in response to a request to activate, when the component is not really available.

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)