# INetDiagHelper::GetRepairInfo

## Description

The **GetRepairInfo** method retrieves the repair information that the Helper Class Extension has for a given problem type.

## Parameters

### `problem` [in]

A [PROBLEM_TYPE](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-problem_type) value that specifies the problem type that the helper class has previously diagnosed.

### `pcelt` [out]

A pointer to a count of elements in the **RepairInfo** array.

### `ppInfo` [out]

A pointer to an array of [RepairInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfo) structures.

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