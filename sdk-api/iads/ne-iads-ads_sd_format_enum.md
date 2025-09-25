# ADS_SD_FORMAT_ENUM enumeration

## Description

The **ADS_SD_FORMAT_ENUM** enumeration specifies the format that the security descriptor of an object will be converted to by the [IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility) interface.

## Constants

### `ADS_SD_FORMAT_IID:1`

Indicates that the security descriptor is to be converted to the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface format. If **ADS_SD_FORMAT_IID** is used as the input format when setting the security descriptor, the variant passed in is expected to be a VT_DISPATCH, where the dispatch pointer supports the **IADsSecurityDescriptor** interface.

### `ADS_SD_FORMAT_RAW:2`

Indicates that the security descriptor is to be converted to the binary format.

### `ADS_SD_FORMAT_HEXSTRING:3`

Indicates that the security descriptor is to be converted to the hex encoded string format.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)

[Security Descriptors on Files and Registry Keys](https://learn.microsoft.com/windows/desktop/ADSI/security-descriptors-on-files-and-registry-keys)