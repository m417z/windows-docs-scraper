# INetDiagHelper::GetHigherHypotheses

## Description

The **GetHigherHypotheses** method asks the Helper Class Extension to generate hypotheses for possible causes of high utilization in the local components that depend on it.

## Parameters

### `pcelt` [out]

A pointer to a count of elements in the HYPOTHESIS array.

### `pprgHypotheses` [out]

A pointer to an array of [HYPOTHESIS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ns-ndhelper-hypothesis) structures.

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