# IComponent::get_Type

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Type** method retrieves an [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) interface describing the general characteristics of the component.

## Parameters

### `CT` [out]

Address of an [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) interface pointer that will be set to the retrieved component.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)