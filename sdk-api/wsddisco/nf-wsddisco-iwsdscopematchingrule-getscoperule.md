# IWSDScopeMatchingRule::GetScopeRule

## Description

Is called to return a URI defining the implemented scope matching rule.

## Parameters

### `ppszScopeMatchingRule` [out]

Pointer to the scope matching rule. The implementer must allocate memory using [WSDAllocateLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdallocatelinkedmemory) and the caller must release memory using [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

**GetScopeRule** should provide a copy of the URI for the scope matching rule this object represents. The copy will be released by the caller using [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).

*ppszScopeMatchingRule* should never be **NULL** or an empty string. To register for the **NULL** scope matching rule, register for the RFC2396 rule as defined in [WS-Discovery](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf). Probe messages containing a **NULL** MatchBy value will be converted to RFC2396 before **GetScopeRule** is called.

## See also

[IWSDScopeMatchingRule](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdscopematchingrule)