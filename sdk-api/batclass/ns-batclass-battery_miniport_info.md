# BATTERY_MINIPORT_INFO structure

## Description

Battery miniclass drivers fill in this structure before calling the battery class driver's [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice) routine.

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

Pointer to the PDO for the battery device.

### `DeviceName`

Pointer to a Unicode string; should be NULL.

## See also

[BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice)