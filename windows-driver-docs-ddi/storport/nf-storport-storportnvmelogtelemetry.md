## Description

An NMVe miniport driver calls the **StorPortNvmeLogTelemetry** function to log telemetry events for an NVMe device.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `ControllerHandle`

[in/optional] For a fabric NVMe miniport, if the event is controller-specific, **ControllerHandle** is StorPort's handle for the NVMe controller. Otherwise, **ControllerHandle** should be NULL.

### `NamespaceId`

[in] If the event is namespace-specific, **NamespaceId** is the namespace identifier. Otherwise, **NamespaceId** should be 0.

### `Event`

[in] Pointer to a [**STORPORT_TELEMETRY_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event) structure that contains standard event fields and miniport payload data.

### `Category`

[in] A [**STOR_TELEMETRY_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_telemetry_category) value that specifies the telemetry category to log.

## Return value

**StorPortNvmeLogTelemetry** returns **STOR_STATUS_SUCCESS** if the telemetry event is successfully logged. Otherwise, it returns a STOR_STATUS error code such as the following:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |

## Remarks

An NVMe miniport can call this function to log a tracelogging measures event with miniport-customized data that is encapsulated in **Event**.

**StorPortNvmeLogTelemetry** additionally allows the caller to specify a telemtry category type.

## See also

[**STOR_TELEMETRY_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_telemetry_category)

[**STORPORT_TELEMETRY_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event)