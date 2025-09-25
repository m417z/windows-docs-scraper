# SAFER_IDENTIFICATION_TYPES enumeration

## Description

The **SAFER_IDENTIFICATION_TYPES** enumeration type defines the possible types of identification rule structures that can be identified by the [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure.

## Constants

### `SaferIdentityDefault`

The header is for a default level structure.

### `SaferIdentityTypeImageName:1`

The header is for a [SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification) structure.

### `SaferIdentityTypeImageHash`

The header is for a [SAFER_HASH_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_hash_identification) structure.

### `SaferIdentityTypeUrlZone`

The header is for a [SAFER_URLZONE_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_urlzone_identification) structure.

### `SaferIdentityTypeCertificate`

The header is for a [SAFER_PATHNAME_IDENTIFICATION](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_pathname_identification) structure.

## Remarks

The **SAFER_IDENTIFICATION_TYPES** enumeration type is used by the [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure.