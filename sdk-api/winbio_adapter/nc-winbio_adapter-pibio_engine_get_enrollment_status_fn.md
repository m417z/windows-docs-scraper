# PIBIO_ENGINE_GET_ENROLLMENT_STATUS_FN callback function

## Description

Called by the Windows Biometric Framework to determine whether the enrollment object is ready to be committed to the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `RejectDetail` [out]

A pointer to a **WINBIO_REJECT_DETAIL** value that receives additional information about the failure to update the enrollment object. If the last update was successful, you should set this variable to zero.

## Return value

This function must return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The last update succeeded and no additional feature sets are required to complete the template. |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| ****WINBIO_E_BAD_CAPTURE**** | The feature set did not meet the internal enrollment requirements of the engine adapter. Further information about the failure is specified by the *RejectDetail* parameter. |
| **WINBIO_E_INVALID_DEVICE_STATE** | There is no enrollment in progress on this biometric unit. |
| ****WINBIO_I_MORE_DATA**** | The last update succeeded, but the engine adapter requires one or more additional feature sets before it can complete the enrollment template. |

## See also

[EngineAdapterUpdateEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_update_enrollment_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)