# PIBIO_ENGINE_SET_ENROLLMENT_SELECTOR_FN callback function

## Description

Called by the Windows Biometric Framework to tell the Engine Adapter which person to track for the current enrollment operation.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SelectorValue` [in]

The enrollment selector value to use.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

For some biometric factors (such as WINBIO_TYPE_FACIAL_FEATURES), there can be multiple people in camera frame at the same time. During an enrollment operation, it’s necessary for the enrollment application to select one specific person to enroll. The enrollment application does this by calling the [WinBioEnrollSelect](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollselect) function. The Windows Biometric Framework then calls the engine adapter’s **EngineAdapterSetEnrollmentSelector** function with this information.

The engine adapter should store this value and use it to track the proper person during the course of the enrollment.