# PIBIO_SENSOR_RESET_FN callback function

## Description

Called by the Windows Biometric Framework to reinitialize the sensor. The specific details of the reset state are determined by the sensor hardware vendor.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A *Pipeline* argument is **NULL**. |
| **WINBIO_E_DEVICE_FAILURE** | There was a hardware failure. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)