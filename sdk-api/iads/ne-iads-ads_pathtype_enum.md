# ADS_PATHTYPE_ENUM enumeration

## Description

The **ADS_PATHTYPE_ENUM** enumeration specifies the type of object on which the [IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility) interface is going to add or modify a security descriptor.

## Constants

### `ADS_PATH_FILE:1`

Indicates that the security descriptor will be retrieved or set on a file object.

### `ADS_PATH_FILESHARE:2`

Indicates that the security descriptor will be retrieved or set on a file share object.

### `ADS_PATH_REGISTRY:3`

Indicates that the security descriptor will be retrieved or set on a registry key object.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)

[Security Descriptors on Files and Registry Keys](https://learn.microsoft.com/windows/desktop/ADSI/security-descriptors-on-files-and-registry-keys)