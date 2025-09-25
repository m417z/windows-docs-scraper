# DOMAINDESC structure

## Description

The **DOMAINDESC** structure contains data about an element in a domain tree obtained with the [IDsBrowseDomainTree::GetDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-getdomains) method. This structure is contained in the [DOMAINTREE](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domain_tree) structure.

## Members

### `pszName`

Pointer to a Unicode string that contains the domain name.

### `pszPath`

Pointer to a Unicode string that contains the path of the domain. Reserved.

### `pszNCName`

Pointer to a Unicode string that contains the fully qualified name of the domain in the form "DC=myDom, DC=Fabrikam, DC=com". This member is blank if the **DBDTF_RETURNFQDN** flag is not set in the *dwFlags* parameter in [IDsBrowseDomainTree::GetDomains](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsbrowsedomaintree-getdomains).

### `pszTrustParent`

Pointer to a Unicode string that contains the name of the parent domain. This member is **NULL** if the domain has no parent.

### `pszObjectClass`

Pointer to a Unicode string that contains the object class name of the domain.

### `ulFlags`

Contains a set of flags that specify the attributes of the trust. For more information, and a list of possible values, see the *Flags* parameter of [DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa).

### `fDownLevel`

Contains a nonzero value if the domain is a down-level domain or zero otherwise.

### `pdChildList`

Contains a pointer to a **DOMAINDESC** structure that represents the first child of the domain. Obtain subsequent children by accessing the **pdNextSibling** member of the child structure. This member is **NULL** if the domain has no children.

### `pdNextSibling`

Contains a pointer to a **DOMAINDESC** structure that represents the next sibling of the domain. Obtain subsequent siblings by accessing the **pdNextSibling** member of the sibling structure. This member is **NULL** if the domain has no siblings.

## Remarks

For more information about how to access and use the information in this structure, see [Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser).

## See also

[DOMAINTREE](https://learn.microsoft.com/windows/desktop/api/dsclient/ns-dsclient-domain_tree)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[Domain Browser](https://learn.microsoft.com/windows/desktop/AD/domain-browser)

[DsEnumerateDomainTrusts](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsenumeratedomaintrustsa)