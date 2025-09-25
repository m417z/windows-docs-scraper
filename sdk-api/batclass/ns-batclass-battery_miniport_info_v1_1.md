# BATTERY_MINIPORT_INFO_V1_1 structure

## Description

Battery miniclass drivers fill in the **BATTERY_MINIPORT_INFO_V1_1** structure before calling the battery class driver's [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice) routine. **BATTERY_MINIPORT_INFO_V1_1** is an updated version of the previous structure [BATTERY_MINIPORT_INFO](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_info).

## Members

### `MajorVersion`

Specifies the major version number of the battery class driver. Miniclass drivers should specify BATTERY_CLASS_MAJOR_VERSION.

### `MinorVersion`

Specifies the minor version number of the battery class driver. Miniclass drivers should specify BATTERY_CLASS_MINOR_VERSION.

### `Context`

Pointer to the context area allocated by the miniclass driver.

### `QueryTag`

Specifies the entry point of the miniclass driver's [BatteryMiniQueryTag](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_tag_callback) routine.

### `QueryInformation`

Specifies the entry point of the miniclass driver's [BatteryMiniQueryInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_information_callback) routine.

### `SetInformation`

Specifies the entry point of the miniclass driver's [BatteryMiniSetInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_information_callback) routine.

### `QueryStatus`

Specifies the entry point of the miniclass driver's [BatteryMiniQueryStatus](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_status_callback) routine.

### `SetStatusNotify`

Specifies the entry point of the miniclass driver's [BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback) routine.

### `DisableStatusNotify`

Specifies the entry point of the miniclass driver's [BatteryMiniDisableStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_disable_status_notify_callback) routine.

### `Pdo`

Pointer to the PDO (physical device object) for the battery device.

### `DeviceName`

Pointer to a Unicode string; should be NULL.

### `Fdo`

Pointer to the FDO (functional device object) for the battery device.