# INetDiagHelper::Initialize

## Description

The **Initialize** method passes in attributes to the Helper Class Extension from the hypothesis. The helper class should store these parameters for use in the main diagnostics functions. This method must be called before any diagnostics function.

## Parameters

### `celt` [in]

A pointer to a count of elements in **HELPER_ATTRIBUTE** array.

### `rgAttributes`

A reference to the [HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute) array.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete this operation. |
| **E_INVALIDARG** | One or more parameters has not been provided correctly. |
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |
| **E_ABORT** | The diagnosis or repair operation has been canceled. |

Helper Class Extensions may return HRESULTS that are specific to the failures encountered in the function.

## Remarks

The Initialize method is required when building a Helper Class Extension.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)