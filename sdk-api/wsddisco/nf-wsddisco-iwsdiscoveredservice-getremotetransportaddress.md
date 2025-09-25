# IWSDiscoveredService::GetRemoteTransportAddress

## Description

Retrieves the string representation of the remote transport (IP) address.

## Parameters

### `ppszRemoteTransportAddress` [out]

String representation of the remote transport (IP) address. Is **NULL** if not available.
Do not deallocate the output string.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszRemoteTransportAddress* is **NULL**. |

## Remarks

The resulting pointer value is only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

The string returned by this method may contain an IPv4 or unbracketed IPv6 address such as "fe80::1". It may also contain a bracketed IPv6 address that includes the port such as "[fe80::1]:1234". The caller should parse the string carefully to account for both possibilities.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)