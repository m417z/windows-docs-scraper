# SAFER_IDENTIFICATION_HEADER structure

## Description

The **SAFER_IDENTIFICATION_HEADER** structure is used as the header for the
[SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification),
[SAFER_HASH_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_hash_identification), and
[SAFER_URLZONE_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_urlzone_identification) structures.

## Members

### `dwIdentificationType`

[SAFER_IDENTIFICATION_TYPES](https://learn.microsoft.com/windows/desktop/api/winsafer/ne-winsafer-safer_identification_types) enumeration value that indicates the type of the structure. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **SaferIdentityDefault** | The header is for a default structure. |
| **SaferIdentityTypeImageName** | The header is for a [SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification) structure. |
| **SaferIdentityTypeImageHash** | The header is for a [SAFER_HASH_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_hash_identification) structure. |
| **SaferIdentityTypeUrlZone** | The header is for a [SAFER_URLZONE_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_urlzone_identification) structure. |
| **SaferIdentityTypeCertificate** | The header is for a [SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification) structure. |

### `cbStructSize`

The size of the entire [SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification),
[SAFER_HASH_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_hash_identification), or
[SAFER_URLZONE_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_urlzone_identification) structure, including the common header.

### `IdentificationGuid`

The GUID of the identification.

### `lastModified`

### `LastModified`

The date and time of the last change to this identification.