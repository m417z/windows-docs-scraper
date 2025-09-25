# PowerIsSettingRangeDefined function

## Description

Queries whether the specified power setting represents a range of possible values.

## Parameters

### `SubKeyGuid` [in, optional]

The identifier of the subkey to search.

### `SettingGuid` [in, optional]

The identifier of the power setting to query.

## Return value

TRUE if the registry key specified by *SubKeyGuid* represents a single power setting.

If the registry key specified by *SubKeyGuid* represents a range, this function returns FALSE.