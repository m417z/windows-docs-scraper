# IWSDiscoveredService::GetProbeResolveTag

## Description

Retrieves the search tag corresponding to this discovered service object.

## Parameters

### `ppszTag` [out]

Search tag passed to the [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) search method that this [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object corresponds to. If the **IWSDiscoveredService** is the result of a Hello message, the tag is **NULL**. Do not deallocate the output string.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppszTag* is **NULL**. |

## Remarks

The resulting pointer value is only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)