# IAzApplication::CreateRole

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

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzRole::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made to the returned object.

The returned [IAzRole](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazrole) object is an immediate child object of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.