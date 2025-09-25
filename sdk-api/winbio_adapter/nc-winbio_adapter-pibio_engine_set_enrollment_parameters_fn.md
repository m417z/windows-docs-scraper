# PIBIO_ENGINE_SET_ENROLLMENT_PARAMETERS_FN callback function

## Description

Called by the Windows Biometric Framework to give the engine adapter additional information about an enrollment operation.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Parameters` [in]

Pointer to the [WINBIO_EXTENDED_ENROLLMENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-enrollment-parameters) structure containing the extended enrollment parameters to use.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

If the engine adapter successfully completes an [EngineAdapterCreateEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_create_enrollment_fn) call, it will immediately receive a call to its **EngineAdapterSetEnrollmentParameters** function.

 This function specifies the subfactor to be used for the new enrollment template.