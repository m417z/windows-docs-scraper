# INetDiagHelper::HighUtilization

## Description

The **HighUtilization** method enables the Helper Class Extension to check whether the corresponding component is highly utilized.

## Parameters

### `pwszInstanceDescription` [in]

A pointer to a null-terminated string containing the user-friendly description of the information being diagnosed. For example, if a class were to diagnosis a connectivity issue with an IP address, the *pwszInstanceDescription* parameter would contain the host name.

### `ppwszDescription` [out]

A pointer to a null-terminated string containing the description of high utilization diagnosis result.

### `pDeferredTime` [out]

A pointer to the time, in seconds, to be deferred if the diagnosis cannot be started immediately. This is used when the *pStatus* parameter is set to **DS_DEFERRED**.

### `pStatus` [out]

A pointer to the [DIAGNOSIS_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-diagnosis_status) that is returned from the diagnosis.

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