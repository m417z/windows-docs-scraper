# PIBIO_SENSOR_SET_MODE_FN callback function

## Description

Called by the Windows Biometric Framework to set the sensor adapter mode.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Mode` [in]

A WINBIO_SENSOR_MODE value. This can be one of the following values:

* WINBIO_SENSOR_UNKNOWN_MODE
* WINBIO_SENSOR_BASIC_MODE
* WINBIO_SENSOR_ADVANCED_MODE
* WINBIO_SENSOR_NAVIGATION_MODE
* WINBIO_SENSOR_SLEEP_MODE

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |
| **WINBIO_E_DEVICE_FAILURE** | There was a hardware failure. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL** or the **SensorHandle** member is set to **INVALID_HANDLE_VALUE**. |
| **WINBIO_E_INVALID_SENSOR_MODE** | The sensor adapter does not support the value specified by the *Mode* parameter. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)