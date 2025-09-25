# ITargetInfo::SetSchemaHiveLocation

## Description

Sets the location of the schema hive.

## Parameters

### `pwzHiveDir` [in]

A pointer to the location of the schema hive.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **E_OUTOFMEMORY** | Indicates that the system is low on resources. |
| **E_INVALIDARG** | Indicates that the location *pwzHiveDir* is not a directory. |

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)