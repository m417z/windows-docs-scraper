# IComponentType::get_Category

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Category** method retrieves the component category.

## Parameters

### `Category` [out]

Pointer to a [ComponentCategory](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/componentcategory) data type that will receive the category.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype)