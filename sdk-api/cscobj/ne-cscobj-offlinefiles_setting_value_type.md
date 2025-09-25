# OFFLINEFILES_SETTING_VALUE_TYPE enumeration

## Description

Identifies the data type returned by the [IOfflineFilesSetting::GetValueType](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessetting-getvaluetype) method.

## Constants

### `OFFLINEFILES_SETTING_VALUE_UI4:0`

A single VT_UI4 value. Used to represent single REG_DWORD values. REG_DWORD is by far the most common type of setting value.

### `OFFLINEFILES_SETTING_VALUE_BSTR`

A single VT_BSTR value. Used to represent single REG_SZ and REG_EXPAND_SZ values.

### `OFFLINEFILES_SETTING_VALUE_BSTR_DBLNULTERM`

A single VT_BSTR value. The string is a double-null-terminated string containing multiple null-terminated substrings. Used to represent single REG_MULTI_SZ values.

### `OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_UI4`

A 2-dimensional array. Each row is a *name,value* pair. Used to represent a set of REG_DWORD values under a registry key of the same name as the setting. Typically, the value names contain UNC paths and the values contain a parameter associated with each UNC path. Column 0 is the value name expressed as VT_BSTR. Column 1 is the VT_UI4 value.

### `OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_BSTR`

A 2-dimensional array. Each row is a *name,value* pair. Used to represent a set of BSTR values under a registry key of the same name as the setting. Typically, the value names contain UNC paths and the values contain a parameter associated with each UNC path. Column 0 is the value name expressed as VT_BSTR. Column 1 is the VT_BSTR value.

## See also

[IOfflineFilesSetting::GetValueType](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessetting-getvaluetype)