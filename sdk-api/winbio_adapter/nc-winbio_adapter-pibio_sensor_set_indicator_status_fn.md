# PIBIO_SENSOR_SET_INDICATOR_STATUS_FN callback function

## Description

Called by the Windows Biometric Framework to toggle the sensor indicator on or off.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `IndicatorStatus` [in]

A **WINBIO_INDICATOR_STATUS** value. This can be one of the following:

* WINBIO_INDICATOR_ON
* WINBIO_INDICATOR_OFF

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter is **NULL**. |
| **E_INVALIDARG** | The *IndicatorStatus* parameter is not correct |
| **WINBIO_E_DEVICE_FAILURE** | There was a hardware failure. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL** or the **SensorHandle** member is set to **INVALID_HANDLE_VALUE**. |
| **WINBIO_E_UNSUPPORTED_PROPERTY** | The sensor does not have an indicator. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterGetIndicatorStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_get_indicator_status_fn)