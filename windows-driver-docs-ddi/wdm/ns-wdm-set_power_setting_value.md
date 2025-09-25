## Description

This topic describes the **SET_POWER_SETTING_VALUE** structure.

## Members

### `Version`

Version of this structure. Currently should be set to **POWER_SETTING_VALUE_VERSION**.

### `Guid`

GUID representing the power setting being applied.

### `PowerCondition`

The power state this setting should be applied to, for example, AC, DC, thermal, and so on.

### `DataLength`

Length in bytes of the **Data** member.

### `Data`

Contains the setting value.

## Remarks

## See also