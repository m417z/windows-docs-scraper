# IADsSecurityUtility::GetSecurityDescriptor

## Description

The **GetSecurityDescriptor** method retrieves a security descriptor for the specified file, fileshare, or registry key.

## Parameters

### `varPath` [in]

A **VARIANT** string that contains the path of the object to retrieve the security descriptor for.

#### File

A valid file path syntax. For example: "c:\specs\public\adxml.doc" or "\\adsi\public\dsclient.exe".

#### File share

A valid file path syntax for a file share. For example: "\\adsi\public".

#### Registry key

A valid registry syntax. For example, "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\ADs".

### `lPathFormat` [in]

Contains one of the [ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum) values which specifies the format of the *varPath* parameter.

### `lFormat` [in]

Contains one of the [ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum) values which specifies the format of the security descriptor returned in the *pVariant* parameter. The following list identifies the possible values for this parameter and the format that is supplied in the *pVariant* parameter.

#### ADS_SD_FORMAT_IID

*pVariant* receives a **VT_DISPATCH** that can be queried for the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface.

#### ADS_SD_FORMAT_RAW

*pVariant* receives a **VT_I1** | **VT_ARRAY** that contains the security descriptor in raw data format. This is in the format of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

#### ADS_SD_FORMAT_HEXSTRING

*pVariant* receives a **VT_BSTR** that contains the raw security descriptor in hex encode string format.

### `pVariant` [out]

Pointer to a **VARIANT** that receives the returned security descriptor. The format of the retrieved security descriptor is specified by the *lFormat* parameter.

## Return value

Returns **S_OK** if successful or a COM or Win32 error code otherwise. Possible error codes include the following.

## See also

[ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum)

[ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SetSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadssecurityutility-setsecuritydescriptor)