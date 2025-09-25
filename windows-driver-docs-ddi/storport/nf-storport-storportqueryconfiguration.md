# StorPortQueryConfiguration function

## Description

A miniport can call **StorPortQueryConfiguration** to query for the specific configuration of the platform.

## Parameters

### `HwDeviceExtension`

Pointer to the hardware device extension for the host bus adapter (HBA).

### `Type`

A [STORPORT_QUERY_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_query_configuration_type) enum value that indicates the type of configuration to query.

### `Enabled`

Pointer to a **BOOLEAN** value in which the Storport driver will return one of the following values.

| Value | Description |
| ----- | ----------- |
| **TRUE** | The configuration specified by *Type* is enabled. |
| **FALSE** | The configuration specified by *Type* is not enabled. |

## Return value

**StorPortQueryConfiguration** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_PARAMETER | *Enabled* is **NULL** or the value specified in *Type* is invalid. |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The query completed successfully. |

## Remarks

## See also

[STORPORT_QUERY_CONFIGURATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_query_configuration_type)