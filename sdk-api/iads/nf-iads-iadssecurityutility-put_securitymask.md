# IADsSecurityUtility::put_SecurityMask

## Description

The **SecurityMask** property determines which elements of the security descriptor to retrieve or set. This property must be set prior to calling [IADsSecurityUtility.GetSecurityDescriptor](https://learn.microsoft.com/windows/win32/api/iads/nf-iads-iadssecurityutility-getsecuritydescriptor) or [IADsSecurityUtility.SetSecurityDescriptor](https://learn.microsoft.com/windows/win32/api/iads/nf-iads-iadssecurityutility-setsecuritydescriptor).

This property is read/write.

## Parameters

### `lnSecurityMask`

Specifies the security information to retrieve or set.

## Return value

An **HRESULT** value that indicates the success or failure of the call.

## See also

[ADS_SECURITY_INFO_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_security_info_enum)

[IADsSecurityUtility](https://learn.microsoft.com/windows/win32/api/iads/nn-iads-iadssecurityutility)

[IADsSecurityUtility.GetSecurityDescriptor](https://learn.microsoft.com/windows/win32/api/iads/nf-iads-iadssecurityutility-getsecuritydescriptor)

[IADsSecurityUtility.SetSecurityDescriptor](https://learn.microsoft.com/windows/win32/api/iads/nf-iads-iadssecurityutility-setsecuritydescriptor)