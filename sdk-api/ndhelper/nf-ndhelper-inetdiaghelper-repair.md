# INetDiagHelper::Repair

## Description

The **Repair** method performs a repair specified by the input parameter.

## Parameters

### `pInfo` [in]

A pointer to a [RepairInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfo) structure.

### `pDeferredTime` [out]

A pointer to the time, in seconds, to be deferred if the repair cannot be started immediately. This is only valid when the pStatus parameter is set to **DS_DEFERRED**.

### `pStatus` [out]

A pointer to the [REPAIR_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-repair_status) that is returned from the repair.

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