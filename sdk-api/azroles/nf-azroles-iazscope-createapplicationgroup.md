# IAzScope::CreateApplicationGroup

## Description

The **CreateApplicationGroup** method creates an [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object with the specified name.

## Parameters

### `bstrGroupName` [in]

Name for the new [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppGroup` [out]

A pointer to a pointer to the created [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.

## Remarks

You must call the [IAzApplicationGroup::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made to the returned object.

The returned [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object is an immediate child object of the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object.