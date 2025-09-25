# IAzScope::CreateRole

## Description

The **CreateRole** method creates an [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object with the specified name.

## Parameters

### `bstrRoleName` [in]

Name for the new [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppRole` [out]

A pointer to a pointer to the created [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [IAzRole::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made to the returned object.

The returned [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object is an immediate child object of the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object.