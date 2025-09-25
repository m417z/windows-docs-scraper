# InstantiateComponentFromPackage function

## Description

Creates an instance of a class in an application package.

## Parameters

### `classId` [in]

The class to activate in the named package.

### `packageFullName` [in]

The full name of the package.

### `instance` [out]

Receives an instance of the class.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **REGDB_E_CLASSNOTREG** | The class is not registered or the class is not listed under the registry key "HKEY_LOCAL_MACHINE\Software\Microsoft\MediaEngine\MediaExtensions\EME\CDMS". See remarks for more info. |

## Remarks

This function can only be used with packages whose "PackageFamilyName" is defined as a subkey key that is registered under the "HKEY_LOCAL_MACHINE\Software\Microsoft\MediaEngine\MediaExtensions\EME\CDMS" key.

 This API should only be called in very exceptional circumstances because code installed from the application store should not be invoked from desktop applications as it is has a lower level of trust associated with it.