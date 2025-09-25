# IWSDiscoveredService::GetInstanceId

## Description

Retrieves the instance identifier of this message.

## Parameters

### `pullInstanceId` [out]

A pointer to the instance identifier of this message.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pullInstanceId* is **NULL**. |

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)