# SecurityDescriptorToBinarySD function

## Description

The **SecurityDescriptorToBinarySD** function converts an [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object to the binary security descriptor format.

## Parameters

### `vVarSecDes` [in]

Type: **VARIANT**

Contains a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that contains the security descriptor to convert. The **VARIANT** must contain a **VT_DISPATCH** that contains an [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object.

### `ppSecurityDescriptor` [out]

Type: **PSECURITY_DESCRIPTOR***

Address of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) pointer that receives the binary security descriptor data. The caller must free this memory by passing this pointer to the [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) function.

### `pdwSDLength` [out]

Type: **PDWORD**

Address of a **DWORD** value that receives the length, in bytes of the binary security descriptor data.

### `pszServerName` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that specifies the name of the server where the security descriptor is placed. This parameter is optional and can be **NULL**.

### `userName` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that contains the user name that the security descriptor is associated to. This parameter is optional and can be **NULL**.

### `passWord` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that contains the password that the security descriptor is associated. This parameter is optional and can be **NULL**.

### `dwFlags` [in]

Type: **DWORD**

Contains authentication flags for the conversion. This can be zero or a combination of one or more of the [ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum) enumeration values.

## Return value

Type: **HRESULT**

This method supports the standard return values, as well as the following.

## Remarks

This function is used for legacy applications to manually convert security descriptors to binary security descriptors. For new applications, use [IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility), which performs this conversion automatically.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum)

[BinarySDToSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-binarysdtosecuritydescriptor)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)