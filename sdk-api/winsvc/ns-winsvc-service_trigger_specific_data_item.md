# SERVICE_TRIGGER_SPECIFIC_DATA_ITEM structure

## Description

Contains trigger-specific data for a service trigger event. This structure is used by the [SERVICE_TRIGGER](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger) structure for SERVICE_TRIGGER_TYPE_CUSTOM, SERVICE_TRIGGER_TYPE_DEVICE_ARRIVAL, SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT, or SERVICE_TRIGGER_TYPE_NETWORK_ENDPOINT trigger events.

## Members

### `dwDataType`

The data type of the trigger-specific data pointed to by **pData**. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_TRIGGER_DATA_TYPE_BINARY**<br><br>1 | The trigger-specific data is in binary format. |
| **SERVICE_TRIGGER_DATA_TYPE_STRING**<br><br>2 | The trigger-specific data is in string format. |
| **SERVICE_TRIGGER_DATA_TYPE_LEVEL**<br><br>3 | The trigger-specific data is a byte value. |
| **SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ANY**<br><br>4 | The trigger-specific data is a 64-bit unsigned integer value. |
| **SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ALL**<br><br>5 | The trigger-specific data is a 64-bit unsigned integer value. |

### `cbData`

The size of the trigger-specific data pointed to **pData**, in bytes. The maximum value is 1024.

### `cbData.range`

### `cbData.range.0`

### `cbData.range.1024`

### `pData`

A pointer to the trigger-specific data for the service trigger event. The trigger-specific data depends on the trigger event type; see Remarks.

If the **dwDataType** member is SERVICE_TRIGGER_DATA_TYPE_BINARY, the trigger-specific data is an array of bytes.

If the **dwDataType** member is SERVICE_TRIGGER_DATA_TYPE_STRING, the trigger-specific data is a null-terminated string or a multistring of null-terminated strings, ending with two null-terminating characters. For example: `"5001\0UDP\0%programfiles%\MyApplication\MyServiceProcess.exe\0MyService\0\0"`.

Strings must be Unicode; ANSI strings are not supported.

### `pData.size_is`

### `pData.size_is.cbData`

## Remarks

The following table lists trigger-specific data by trigger event type.

| Event type | Trigger-specific data |
| --- | --- |
| SERVICE_TRIGGER_TYPE_CUSTOM | Specified by the [Event Tracing for Windows](https://learn.microsoft.com/windows/win32/etw/event-tracing-portal) (ETW) provider that defines the custom event. |
| SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL | A SERVICE_TRIGGER_DATA_TYPE_STRING string that specifies a hardware ID or compatible ID string for the device interface class. |
| SERVICE_TRIGGER_TYPE_DOMAIN_JOIN | Not applicable. |
| SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT | A SERVICE_TRIGGER_DATA_TYPE_STRING multi-string that specifies the port, the protocol, and optionally the executable path and name of the service listening on the event. |
| SERVICE_TRIGGER_TYPE_GROUP_POLICY | Not applicable. |
| SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY | Not applicable. |
| SERVICE_TRIGGER_TYPE_NETWORK_ENDPOINT | A SERVICE_TRIGGER_DATA_TYPE_STRING that specifies the port, named pipe, or RPC interface for the network endpoint. |

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[SERVICE_TRIGGER](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_trigger)

[Service Trigger Events](https://learn.microsoft.com/windows/desktop/Services/service-trigger-events)