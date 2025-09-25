# CERT_OTHER_LOGOTYPE_INFO structure

## Description

The **CERT_OTHER_LOGOTYPE_INFO** structure contains information about logo types that are not predefined.

## Members

### `pszObjId`

The address of a null-terminated ANSI string that contains the object identifier of the logo type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **szOID_LOYALTY_OTHER_LOGOTYPE**<br><br>"1.3.6.1.5.5.7.20.1" | The logo is a loyalty logo. |
| **szOID_BACKGROUND_OTHER_LOGOTYPE**<br><br>"1.3.6.1.5.5.7.20.2" | The logo is a background logo. |

### `LogotypeInfo`

A [CERT_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_info) structure that contains the logo type information.