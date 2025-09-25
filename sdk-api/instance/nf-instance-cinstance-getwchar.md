# CInstance::GetWCHAR

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetWCHAR** method retrieves a **WCHAR** string property.

## Parameters

### `name`

Name of the **WCHAR** string property retrieved.

### `pW`

Buffer that receives the **WCHAR** string property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to retrieve a property that is not a type that is **WCHAR** string-compatible or a property that does not exist. More information is available in the log file, Framework.log.

## Remarks

It is the responsibility of the implementer to free the memory occupied by the **WCHAR** string:

```cpp
    free(pw);
```

Use **free** rather than **delete** because the provider framework allocates the string using **malloc** and does not use the **new** operator.