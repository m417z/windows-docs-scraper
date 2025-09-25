# SAFER_URLZONE_IDENTIFICATION structure

## Description

The **SAFER_URLZONE_IDENTIFICATION** structure represents a URL zone identification rule.

## Members

### `header`

### `UrlZoneId`

A URLZONE identifier that represents the origin of the code image to be checked. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **URLZONE_LOCAL_MACHINE** | The local machine. |
| **URLZONE_INTRANET** | The current intranet. |
| **URLZONE_TRUSTED** | A trusted URL zone. |
| **URLZONE_INTERNET** | The Internet. |
| **URLZONE_UNTRUSTED** | An untrusted URL zone. |

### `dwSaferFlags`

Reserved for future use.

### `Header`

A [SAFER_IDENTIFICATION_HEADER](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_identification_header) structure containing the structure header. The **dwIdentificationType** member of the header must be **SaferIdentityTypeUrlZone**, and the **cbStructSize** member of the header must be sizeof(SAFER_URLZONE_IDENTIFICATION).