# IAzScope::OpenApplicationGroup

## Description

The **OpenApplicationGroup** method opens an [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object with the specified name.

## Parameters

### `bstrGroupName` [in]

Name of the [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppGroup` [out]

A pointer to a pointer to the opened [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.