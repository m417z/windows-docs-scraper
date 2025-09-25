# IDsBrowseDomainTree::BrowseTo

## Description

The **IDsBrowseDomainTree::BrowseTo** method displays a dialog box used to browse for a domain.

## Parameters

### `hwndParent` [in]

Handle of the window that will be the owner of the domain browser dialog box.

### `ppszTargetPath` [out]

Pointer to a Unicode string pointer that receives the path string of the domain selected in the domain browser. This memory must be freed when it is no longer required by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). By default, this path takes the form "myDom.Fabrikam.com". If *dwFlags* contains the **DBDTF_RETURNFQDN** flag, the path takes the form "DC=myDom, DC=Fabrikam, DC=com".

### `dwFlags` [in]

Contains a set of flags that modify the behavior of the domain browser dialog box. This can be zero or a combination of one or more of the following values.

#### DBDTF_RETURNFQDN

The domain browser will place the fully qualified domain name in *ppszTargetPath*. The fully qualified domain name takes the form "DC=myDom, DC=Fabrikam, DC=com" as opposed to "myDom.Fabrikam.com".

#### DBDTF_RETURNMIXEDDOMAINS

The domain browser will display downlevel trust domains.

#### DBDTF_RETURNEXTERNAL

The domain browser will display external trust domains.

#### DBDTF_RETURNINBOUND

If this flag is set, the domain browser will display trusting domains. Otherwise, the domain browser will display trusted domains.

#### DBDTF_RETURNINOUTBOUND

The domain browser will display both trusted and trusting domains.

## Return value

Returns a standard **HRESULT** value including the following.

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IDsBrowseDomainTree](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsbrowsedomaintree)