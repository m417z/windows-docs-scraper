# IWSDiscoveryPublisher::RegisterScopeMatchingRule

## Description

Adds support for a custom scope matching rule.

## Parameters

### `pScopeMatchingRule` [in]

Pointer to an [IWSDScopeMatchingRule](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdscopematchingrule) object that represents a custom scope matching rule.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *pScopeMatchingRule* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

**RegisterScopeMatchingRule** allows custom scope matching rules to be defined and added to the existing set defined in the [WS-Discovery specification](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf).

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)