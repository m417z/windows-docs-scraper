## Description

**StorPortCaptureLiveDump** captures a live dump file.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport's hardware device extension.

### `StorAddress` [in/optional]

Pointer to a [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address) structure that holds the address specifying the unit object. Set **StorAddress** to NULL if the device is an adapter.

### `CaptureLivedump` [in]

Pointer to a [**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump) structure containing the data needed to generate the live dump.

## Return value

**StorPortCaptureLiveDump** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The dump feature list was set successfully. |
| STOR_STATUS_INVALID_PARAMETER | One or more of the provided parameters are invalid. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

When a miniport detects an issue that might require further triage, it can call **StorPortCaptureLiveDump** to capture a live dump file.

This function must be called at PASSIVE_LEVEL.

## See also

[**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_address)

[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump)

[**STORPORT_LIVEDUMP_DATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_data_type)

[**STORPORT_LIVEDUMP_DEVICE_TELEMETRY_LOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_livedump_device_telemetry_log)