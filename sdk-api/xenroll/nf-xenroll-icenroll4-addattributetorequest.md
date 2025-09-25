# ICEnroll4::addAttributeToRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addAttributeToRequest** method adds an [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `Flags` [in]

This parameter is reserved for future use and must be set to zero.

### `strName` [in]

An [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that represents the attribute name.

### `strValue` [in]

A base64-encoded or binary attribute value.

## Return value

### VB

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).