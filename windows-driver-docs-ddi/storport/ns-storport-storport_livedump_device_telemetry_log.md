## Description

**STORPORT_LIVEDUMP_DEVICE_TELEMETRY_LOG** contains the payload for a live dump captured by [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump).

## Members

### `Version`

Size, in bytes, of this structure. The structure size serves as the version.

### `Size`

Size, in bytes, of this structure plus all of its variable-sized fields.

### `BucketId`

Unique identifier for the device's state when the issue occurs.

### `OrganizationID`

The IEEE organizationally unique identifier (OUI).

### `Reserved`

Reserved; do not use.

### `TelemetryLength`

Size, in bytes, of the telemetry log that **DeviceTelemetry** points to.

### `DeviceTelemetry`

Pointer to the device-defined telemetry log.

## Remarks

When a miniport calls [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump) with [**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump).**DataType** set to **StorportLivedumpDataTypeDeviceTelemetryLog**, **STORPORT_CAPTURE_LIVEDUMP.Data** points to a **STORPORT_LIVEDUMP_DEVICE_TELEMETRY_LOG** structure that contains the payload for the live dump.

## See also

[**STORPORT_LIVEDUMP_DATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_data_type)

[**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump)