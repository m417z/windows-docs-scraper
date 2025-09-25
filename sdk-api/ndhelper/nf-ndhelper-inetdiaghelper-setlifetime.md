# INetDiagHelper::SetLifeTime

## Description

The **SetLifeTime** method is called by NDF to set the start and end time of interest to diagnostics so that the Helper Class Extension can limit its diagnosis to events within that time period.

## Parameters

### `lifeTime` [in]

A [LIFE_TIME](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-life_time) structure.

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