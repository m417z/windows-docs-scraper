# INetDiagHelper::GetKeyAttributes

## Description

The **GetKeyAttributes** method retrieves the key attributes of the Helper Class Extension.

## Parameters

### `pcelt` [out]

A pointer to a count of elements in the **HELPER_ATTRIBUTE** array.

### `pprgAttributes` [out]

A pointer to an array of [HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute) structures.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |
| **E_NOTIMPL** | This optional method is not implemented. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |
| **E_ABORT** | The diagnosis or repair operation has been canceled. |

Helper Class Extensions may return HRESULTS that are specific to the failures encountered in the function.

## Remarks

This method is not required when building a Helper Class Extension.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)