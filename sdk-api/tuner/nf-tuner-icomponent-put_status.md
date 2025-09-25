# IComponent::put_Status

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Status** method sets the requested or actual status of the component.

## Parameters

### `Status` [in]

A variable of type [ComponentStatus](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/componentstatus) that specifies the status value.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

Use this method to activate or inactivate a stream component.

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)

[IComponent::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponent-get_status)