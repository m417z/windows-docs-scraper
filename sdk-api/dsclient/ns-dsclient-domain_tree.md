# DOMAIN_TREE structure

## Description

The **DOMAINTREE** structure contains data about a node in a domain tree obtained with the [IDsBrowseDomainTree::GetDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-getdomains) method. Each of the domains in the tree node are represented by a
[DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc) structure.

## Members

### `dsSize`

Contains the size, in bytes, of the **DOMAINTREE** structure and all [DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc) structures in this **DOMAINTREE** structure.

### `dwCount`

Contains the number of [DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc) structures in the **aDomains** array.

### `aDomains`

Contains an array of [DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc) structures that represent the domains. The array does not contain any child or sibling relational data. The relational data is contained within the **DOMAINDESC** structures.

## Remarks

For more information about how to access and use the data in this structure, see [Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser).

## See also

[DOMAINDESC](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domaindesc)

[Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser)

[IDsBrowseDomainTree::FreeDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-freedomains)

[IDsBrowseDomainTree::GetDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-getdomains)