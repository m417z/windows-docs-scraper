## Description

**STORPORT_LIVEDUMP_DATA_TYPE** identifies the data type of the payload to be included in the live dump.

## Constants

### `StorportLivedumpDataTypeUndefined`

Reserved for system use; do not use.

### `StorportLivedumpDataTypeDeviceTelemetryLog`

Include a payload of type [**STORPORT_LIVEDUMP_DEVICE_TELEMETRY_LOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_livedump_device_telemetry_log).

## Remarks

**STORPORT_LIVEDUMP_DATA_TYPE** identifies the payload structure pointed to by the **Data** member of the[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump) structure, which a miniport passes when it calls [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump).

## See also

[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump)

[**STORPORT_LIVEDUMP_DEVICE_TELEMETRY_LOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_livedump_device_telemetry_log)

[**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump)