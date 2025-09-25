# IAzApplication::OpenRole

## Description

The **OpenRole** method opens an [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object with the specified name.

## Parameters

### `bstrRoleName` [in]

Name of the [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppRole` [out]

A pointer to a pointer to the opened [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.