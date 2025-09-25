# PIBIO_ENGINE_QUERY_EXTENDED_ENROLLMENT_STATUS_FN callback function

## Description

Called by the Windows Biometric Framework when a client application queries the **WINBIO_PROPERTY_EXTENDED_ENROLLMENT_STATUS** property.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `EnrollmentStatus` [out]

Pointer to the [WINBIO_EXTENDED_ENROLLMENT_STATUS](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-enrollment-status) structure that contains the extended enrollment status information returned by this function.

### `EnrollmentStatusSize` [in]

The specified size in bytes of the extended enrollment status information.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **E_INVALIDARG** | The *EnrollmentStatusSize* parameter indicates that the output buffer is too small. |

## Remarks

Enrollment applications can request extended enrollment status information after each call to the [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture) function.

If the biometric unit is not currently an enrollment template when this routine is called, the engine adapter should set the EnrollmentStatus.TemplateStatus field to **WINBIO_E_INVALID_OPERATION** and return **S_OK** as the value of the function.