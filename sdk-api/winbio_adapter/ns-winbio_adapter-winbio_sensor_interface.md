# WINBIO_SENSOR_INTERFACE structure

## Description

The **WINBIO_SENSOR_INTERFACE** structure contains pointers to your custom sensor adapter functions. The Windows Biometric Framework uses this structure to locate the functions.

## Members

### `Version`

Version number of this structure.

**Windows 10:** The version number must be **WINBIO_SENSOR_INTERFACE_VERSION_3**.

**Windows Server 2012 R2, Windows 8.1, Windows Server 2012 and Windows 8:** The version number must be **WINBIO_SENSOR_INTERFACE_VERSION_2**.

**Windows Server 2008 R2 and Windows 7:** The version number must be **WINBIO_SENSOR_INTERFACE_VERSION_1**.

### `Type`

The type of adapter. This must be **WINBIO_ADAPTER_TYPE_SENSOR**.

### `Size`

The size, in bytes, of this structure. Set this value to the size of the **WINBIO_SENSOR_INTERFACE** structure.

### `AdapterId`

A GUID that uniquely identifies the sensor adapter. You must generate this value.

### `Attach`

A pointer to your implementation of the [SensorAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_attach_fn) function.

### `Detach`

A pointer to your implementation of the [SensorAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_detach_fn) function.

### `ClearContext`

A pointer to your implementation of the [SensorAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_clear_context_fn) function.

### `QueryStatus`

A pointer to your implementation of the [SensorAdapterQueryStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_query_status_fn) function.

### `Reset`

A pointer to your implementation of the [SensorAdapterReset](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_reset_fn) function.

### `SetMode`

A pointer to your implementation of the [SensorAdapterSetMode](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_set_mode_fn) function.

### `SetIndicatorStatus`

A pointer to your implementation of the [SensorAdapterSetIndicatorStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_set_indicator_status_fn) function.

### `GetIndicatorStatus`

A pointer to your implementation of the [SensorAdapterGetIndicatorStatus](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_get_indicator_status_fn) function.

### `StartCapture`

A pointer to your implementation of the [SensorAdapterStartCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_start_capture_fn) function.

### `FinishCapture`

A pointer to your implementation of the [SensorAdapterFinishCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_finish_capture_fn) function.

### `ExportSensorData`

A pointer to your implementation of the [SensorAdapterExportSensorData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_export_sensor_data_fn) function.

### `Cancel`

A pointer to your implementation of the [SensorAdapterCancel](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_cancel_fn) function.

### `PushDataToEngine`

A pointer to your implementation of the [SensorAdapterPushDataToEngine](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_push_data_to_engine_fn) function.

### `ControlUnit`

A pointer to your implementation of the [SensorAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_control_unit_fn) function.

### `ControlUnitPrivileged`

A pointer to your implementation of the [SensorAdapterControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_control_unit_privileged_fn) function.

### `NotifyPowerChange`

A pointer to your implementation of the [SensorAdapterNotifyPowerChange](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_notify_power_change_fn) function. This member is supported starting in Windows 8.

### `PipelineInit`

A pointer to your implementation of the [SensorAdapterPipelineInit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_pipeline_init_fn) function. This member is supported starting in Windows 10.

### `PipelineCleanup`

A pointer to your implementation of the [SensorAdapterPipelineCleanup](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_pipeline_cleanup_fn) function. This member is supported starting in Windows 10.

### `Activate`

A pointer to your implementation of the [SensorAdapterActivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_activate_fn) function. This member is supported starting in Windows 10.

### `Deactivate`

A pointer to your implementation of the [SensorAdapterDeactivate](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_deactivate_fn) function. This member is supported starting in Windows 10.

### `QueryExtendedInfo`

A pointer to your implementation of the [SensorAdapterQueryExtendedInfo](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_query_extended_info_fn) function. This member is supported starting in Windows 10.

### `QueryCalibrationFormats`

A pointer to your implementation of the [SensorAdapterQueryCalibrationFormats](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_query_calibration_formats_fn) function. This member is supported starting in Windows 10.

### `SetCalibrationFormat`

A pointer to your implementation of the [SensorAdapterSetCalibrationFormat](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_set_calibration_format_fn) function. This member is supported starting in Windows 10.

### `AcceptCalibrationData`

A pointer to your implementation of the [SensorAdapterAcceptCalibrationData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_accept_calibration_data_fn) function. This member is supported starting in Windows 10.

### `AsyncImportRawBuffer`

### `AsyncImportSecureBuffer`

### `QueryPrivateSensorType`

### `ConnectSecure`

### `StartCaptureEx`

### `StartNotifyWake`

### `FinishNotifyWake`

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[Plug-in Structures](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-structures)

[WbioQuerySensorInterface](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nf-winbio_adapter-wbioquerysensorinterface)