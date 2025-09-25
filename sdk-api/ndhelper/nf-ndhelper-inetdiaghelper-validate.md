# INetDiagHelper::Validate

## Description

The **Validate** method is called by NDF after a repair is successfully completed in order to validate that a previously diagnosed problem has been fixed.

## Parameters

### `problem` [in]

The [PROBLEM_TYPE](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-problem_type) that the helper class has previously diagnosed.

### `pDeferredTime` [out]

A pointer to the time to be deferred, in seconds, if the diagnosis cannot be started immediately. This is used only when the pStatus member is set to **DS_DEFERRED**.

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

This method only returns an error code if it encounters failures that impede validation. If necessary, the *pStatus* parameter is the expected way to communicate that the component is still in low health. **DS_REJECTED** is used to indicate that the issue has been resolved.

## See also

[INetDiagHelper](https://learn.microsoft.com/windows/desktop/api/ndhelper/nn-ndhelper-inetdiaghelper)