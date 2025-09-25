# IWSDiscoveredService::GetLocalTransportAddress

## Description

Retrieves the string representation of the local transport (IP) address.

## Parameters

### `ppszLocalTransportAddress` [out]

String representation of the local transport (IP) address. Is **NULL** if not available.
Do not deallocate the output string.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszLocalTransportAddress* is **NULL**. |

## Remarks

The resulting pointer value is only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)