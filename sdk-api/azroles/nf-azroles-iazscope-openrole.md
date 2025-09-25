# IAzScope::OpenRole

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

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.