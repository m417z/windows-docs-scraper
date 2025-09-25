# IADsSecurityUtility::ConvertSecurityDescriptor

## Description

The **ConvertSecurityDescriptor** method converts a security descriptor from one format to another.

## Parameters

### `varSD` [in]

A **VARIANT** that contains the security descriptor to convert. The format of this **VARIANT** is defined by the *lDataFormat* parameter.

### `lDataFormat` [in]

Contains one of the [ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum) values which specifies the format of the security descriptor in the *varSD* parameter. The following list identifies the possible values for this parameter and the format of the *varSD* parameter.

#### ADS_SD_FORMAT_IID

*varSD* contains a **VT_DISPATCH** that can be queried for the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface.

#### ADS_SD_FORMAT_RAW

*varSD* contains a **VT_I1** | **VT_ARRAY** that contains the security descriptor in raw data format. This is in the format of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

#### ADS_SD_FORMAT_HEXSTRING

*varSD* contains a **VT_BSTR** that contains the raw security descriptor in hex encode string format.

### `lOutFormat` [in]

Contains one of the [ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum) values which specifies the format that the security descriptor should be converted to. The following list identifies the possible values for this parameter and the format of the *pvResult* parameter.

#### ADS_SD_FORMAT_IID

*pvResult* receives a **VT_DISPATCH** that can be queried for the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface.

#### ADS_SD_FORMAT_RAW

*pvResult* receives a **VT_I1** | **VT_ARRAY** that contains the security descriptor in raw data format. This is in the format of a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

#### ADS_SD_FORMAT_HEXSTRING

*pvResult* receives a **VT_BSTR** that contains the raw security descriptor in hex encode string format.

### `pResult` [out]

Pointer to a **VARIANT** that receives the converted security descriptor. The format of the retrieved security descriptor is specified by the *lOutFormat* parameter.

## Return value

Returns **S_OK** if successful or a COM or Win32 error code otherwise. Possible error codes include the following.

## See also

[ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum)

[ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)