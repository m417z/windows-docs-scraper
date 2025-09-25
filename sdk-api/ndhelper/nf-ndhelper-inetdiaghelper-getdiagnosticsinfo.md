# INetDiagHelper::GetDiagnosticsInfo

## Description

The **GetDiagnosticsInfo** method enables the Helper Class Extension instance to provide an estimate of how long the diagnosis may take.

## Parameters

### `ppInfo` [out]

A pointer to a pointer to a [DiagnosticsInfo](https://learn.microsoft.com/windows/desktop/api/ndhelper/ns-ndhelper-diagnosticsinfo) structure.

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

The GetDiagnosticsInfo method is required when building a Helper Class Extension.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)