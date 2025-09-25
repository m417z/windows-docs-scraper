# BinarySDToSecurityDescriptor function

## Description

The **BinarySDToSecurityDescriptor** function converts a binary security descriptor to an [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object.

## Parameters

### `pSecurityDescriptor` [in]

Type: **PSECURITY_DESCRIPTOR**

Address of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to convert.

### `pVarsec` [out]

Type: **VARIANT***

Address of a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that receives the object. The **VARIANT** contains a **VT_DISPATCH** object that can be queried for the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface. The caller must release this **VARIANT** by passing the **VARIANT** to the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function.

### `pszServerName` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that provides the name of the server that the security descriptor was retrieved from. This parameter is optional and can be **NULL**.

### `userName` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that provides the user name to be associated with the security descriptor. This parameter is optional and can be **NULL**.

### `passWord` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that provides the password to be associated with the security descriptor. This parameter is optional and can be **NULL**.

### `dwFlags` [in]

Type: **DWORD**

Contains authentication flags for the conversion. This can be zero or a combination of one or more of the [ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum) enumeration values.

## Return value

Type: **HRESULT**

This method supports standard return values, as well as the following:

If the operation fails, an ADSI error code is returned. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This function is used for legacy applications that must manually convert security descriptors to binary security descriptors. For new applications, use the [IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility) interface, which does this conversion automatically.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SecurityDescriptorToBinarySD](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-securitydescriptortobinarysd)

[VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear)