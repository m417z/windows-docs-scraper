# IWSDiscoveredService::GetLocalInterfaceGUID

## Description

Retrieves the GUID of the local network interface over which the message was received.

## Parameters

### `pGuid` [out]

GUID of the local network interface over which the message was received. Structure will be cleared if the local interface GUID is not available.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pGuid* is **NULL**. |

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)