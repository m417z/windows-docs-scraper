# ISharedProperty::put_Value

## Description

Sets the value of a shared property.

## Parameters

### `val` [in]

The new value that is to be set for this shared property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **DISP_E_ARRAYISLOCKED** | The argument passed in the parameter contains an array that is locked. |
| **DISP_E_BADVARTYPE** | The argument passed in the parameter is not a valid Variant type. |

## See also

[ISharedProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedproperty)

[SharedProperty](https://learn.microsoft.com/windows/desktop/cossdk/sharedproperty)