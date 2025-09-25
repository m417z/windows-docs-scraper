# IRegisteredSyncProvider::Init

## Description

Initializes the synchronization provider before it is ready for a synchronization session.

## Parameters

### `pguidInstanceId` [in]

The instance ID of the synchronization provider.

### `pguidContentType` [in]

A GUID that represents the content type that this provider will synchronize.

### `pContextPropertyStore` [in]

The properties needed to initialize the synchronization provider. These properties are also provided when the synchronization provider is registered.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IRegisteredSyncProvider Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-iregisteredsyncprovider)