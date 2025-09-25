# IWSDiscoveryPublisher::UnRegisterScopeMatchingRule

## Description

Removes support for a custom scope matching rule.

## Parameters

### `pScopeMatchingRule` [in]

Pointer to an [IWSDScopeMatchingRule](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdscopematchingrule) object that represents a custom scope matching rule.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *pScopeMatchingRule* is **NULL**. |

## Remarks

**UnRegisterScopeMatchingRule** removes a previously associated custom scope matching rule.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)