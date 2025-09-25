# ITargetInfo::GetSchemaHiveLocation

## Description

Get the location of the schema hive.

## Parameters

### `pHiveLocation` [out]

A pointer to the schema hive location.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **S_FALSE** if the location is not set. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)