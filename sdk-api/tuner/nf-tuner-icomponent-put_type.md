# IComponent::put_Type

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Type** method sets an [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) object describing the general characteristics of the component.

## Parameters

### `CT` [in]

Pointer to an [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) object that specifies the new values for the component.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

Using the [IComponent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent) base class interface, it is possible to set the type to be **NULL**. If you try to do this with the derived [IMPEG2Component](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-impeg2component) class interface, this method will return E_POINTER. The **IMPEG2Component** object cannot have the base [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) class interface as the set type - this will return Type Mismatch (0x80020005).

## See also

[IComponent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent)