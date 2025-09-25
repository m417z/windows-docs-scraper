# PIBIO_SENSOR_GET_INDICATOR_STATUS_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve a value that indicates whether the sensor indicator is on or off.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `IndicatorStatus` [out]

Pointer to a **WINBIO_INDICATOR_STATUS** value. This can be one of the following:

* WINBIO_INDICATOR_ON
* WINBIO_INDICATOR_OFF

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **WINBIO_E_DEVICE_FAILURE** | There was a hardware failure. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL** or the **SensorHandle** member is set to **INVALID_HANDLE_VALUE**. |
| **WINBIO_E_UNSUPPORTED_PROPERTY** | The sensor does not have an indicator. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterSetIndicatorStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_set_indicator_status_fn)