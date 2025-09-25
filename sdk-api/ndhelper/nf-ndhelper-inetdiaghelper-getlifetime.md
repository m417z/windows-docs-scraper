# INetDiagHelper::GetLifeTime

## Description

The **GetLifeTime** method retrieves the lifetime of the Helper Class Extension instance.

## Parameters

### `pLifeTime` [out]

A pointer to a [LIFE_TIME](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-life_time) structure.

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

Lifetime data is used to limit the time scope of a problem instance. This is particularly useful when doing history-based diagnoses such as tracing and logging where it can be used in scoping down the diagnosis to events that occurred during the specified time interval.

For example, Windows Filtering Platform (WFP) helper classes use lifetime to determine which filter blocked a packet by checking the trace log. By default, a lifetime of a helper class instance inherits the lifetime of its dependent helper class instance.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)