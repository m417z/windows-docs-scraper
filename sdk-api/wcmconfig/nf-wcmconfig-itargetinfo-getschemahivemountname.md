# ITargetInfo::GetSchemaHiveMountName

## Description

Gets the name of the mount location of the schema hive.

## Parameters

### `pMountName` [out]

The name of the mount location of the schema hive. The value of *pMountName* is **NULL** on return if the default name is to be used.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo)