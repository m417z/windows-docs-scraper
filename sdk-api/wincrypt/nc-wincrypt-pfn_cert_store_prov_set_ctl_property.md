# PFN_CERT_STORE_PROV_SET_CTL_PROPERTY callback function

## Description

The **CertStoreProvSetCTLProperty** callback function determines whether a property can be set on a CTL. It is called by
[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty) before setting a CTL's property. It can also be called by
[CertGetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetctlcontextproperty), when getting a hash property that needs to be created and then persisted. This callback function does not set the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)'s property.

## Parameters

### `hStoreProv` [in]

A handle to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `pCtlContext` [in]

A pointer to a
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure.

### `dwPropId` [in]

Identifier of the property to be set.

### `dwFlags` [in]

Any needed flag values.

### `pvData` [in]

A pointer to a buffer containing the property value to be set.

## Return value

Returns **TRUE** if the property can be set. Returns **FALSE** if the property cannot be set.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CertGetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetctlcontextproperty)

[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty)