# POWERBROADCAST_SETTING structure

## Description

Sent with a power setting event and contains data about the specific change. For more
information, see [Registering for Power
Events](https://learn.microsoft.com/windows/desktop/Power/registering-for-power-events) and [Power Setting GUIDs](https://learn.microsoft.com/windows/desktop/Power/power-setting-guids).

## Members

### `PowerSetting`

Indicates the power setting for which this notification is being delivered. For more
info, see [Power Setting GUIDs](https://learn.microsoft.com/windows/desktop/Power/power-setting-guids).

### `DataLength`

The size in bytes of the data in the *Data* member.

### `Data`

The new value of the power setting. The type and possible values for this member depend on *PowerSettng.*

## See also

[Power Setting GUIDs](https://learn.microsoft.com/windows/desktop/Power/power-setting-guids)

[Registering for Power Events](https://learn.microsoft.com/windows/desktop/Power/registering-for-power-events)