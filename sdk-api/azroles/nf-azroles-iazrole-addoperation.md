# IAzRole::AddOperation

## Description

The **AddOperation** method adds the [IAzOperation](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazoperation) object with the specified name to the role.

## Parameters

### `bstrProp` [in]

Name of the [IAzOperation](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazoperation) object to add to the role.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.

## See also

[IAzOperation](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazoperation)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit)