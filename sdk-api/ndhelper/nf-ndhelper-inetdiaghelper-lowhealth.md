# INetDiagHelper::LowHealth

## Description

The **LowHealth** method enables the Helper Class Extension to check whether the component being diagnosed is healthy.

## Parameters

### `pwszInstanceDescription` [in]

A pointer to a null-terminated string containing the user-friendly description of the information being diagnosed. For example, if a class were to diagnosis a connectivity issue with an IP address, the *pwszInstanceDescription* parameter would contain the host name.

### `ppwszDescription` [out]

A pointer to a null-terminated string containing the description of the issue found if the component is found to be unhealthy.

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
| **E_ACCESSDENIED** | The caller does not have sufficient privileges to perform the diagnosis or repair operation. |
| **E_ABORT** | The diagnosis or repair operation has been canceled. |

Helper Class Extensions may return HRESULTS that are specific to the failures encountered in the function.

## Remarks

The LowHealth method is required when building a Helper Class Extension.

If LowHealth returns **DS_CONFIRMED**, *ppwszDescription* will also contain a user-friendly description of the diagnosis result. The out parameter *pDeferredTime* contains the number of seconds this diagnosis needs to be deferred if pStatus returns **DS_DEFERRED**.

When LowHealth is confirmed, it may also optionally generate hypotheses in the [GetLowerHypotheses](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-getlowerhypotheses) method for other helper classes if the problem may be caused by other components. If not confirmed, NDF may further diagnose the problem by calling [HighUtilization](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-highutilization).

LowHealth may also return **DS_INDETERMINATE** if it is unable to diagnose the problem, but cannot confirm that the component is healthy. In this case, NDF will treat it as **DS_CONFIRMED** if none of the other hypotheses are confirmed.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)