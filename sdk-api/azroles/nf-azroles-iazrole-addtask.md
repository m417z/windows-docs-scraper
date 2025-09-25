# IAzRole::AddTask

## Description

The **AddTask** method adds the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object with the specified name to the role.

## Parameters

### `bstrProp` [in]

Name of the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object to add to the role.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.

## See also

[IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit)