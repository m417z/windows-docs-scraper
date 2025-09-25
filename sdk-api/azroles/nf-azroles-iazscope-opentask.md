# IAzScope::OpenTask

## Description

The **OpenTask** method opens an [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object with the specified name.

## Parameters

### `bstrTaskName` [in]

Name of the [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppTask` [out]

A pointer to a pointer to the opened [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Any other value indicates that the operation failed.