# IDsBrowseDomainTree::GetDomains

## Description

The **IDsBrowseDomainTree::GetDomains** method retrieves the trust domains of the current computer.
The current computer is set using the [IDsBrowseDomainTree::SetComputer](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-setcomputer) method.

## Parameters

### `ppDomainTree` [in]

Pointer to a [DOMAINTREE](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domain_tree) structure pointer that receives the trust domain data. The caller must free this memory when no longer required by calling [IDsBrowseDomainTree::FreeDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-freedomains).

### `dwFlags` [in]

Contains a set of flags that modify the domain contents. This can be zero or a combination of one or more of the following values.

#### DBDTF_RETURNFQDN

The **pszNCName** members of the [DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc) structures will receive the fully qualified domain names. The fully qualified domain name takes the form "DC=myDom, DC=Fabrikam, DC=com" as opposed to "myDom.Fabrikam.com".

#### DBDTF_RETURNMIXEDDOMAINS

The method will return downlevel trust domains.

#### DBDTF_RETURNEXTERNAL

The method will return external trust domains.

#### DBDTF_RETURNINBOUND

If this flag is set, the method returns trusting domains. If this flag is not set, the method returns trusted domains.

#### DBDTF_RETURNINOUTBOUND

The method will return both trusted and trusting domains.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

For more information about how to access and use the data provided by this method, see [Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser).

## See also

[DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc)

[DOMAINTREE](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domain_tree)

[Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser)

[IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree)

[IDsBrowseDomainTree::FreeDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-freedomains)