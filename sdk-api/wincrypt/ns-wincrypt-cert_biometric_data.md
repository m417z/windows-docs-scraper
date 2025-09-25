# CERT_BIOMETRIC_DATA structure

## Description

The **CERT_BIOMETRIC_DATA** structure contains information about biometric data.

## Members

### `dwTypeOfBiometricDataChoice`

Specifies the type of biometric data. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE** | The biometric data type is one of the predefined data types. The **dwPredefined** member specifies the data type. |
| **CERT_BIOMETRIC_OID_DATA_CHOICE** | The biometric data type is identified by the **pszObjId** member. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.dwPredefined`

Specifies one of the predefined biometric data types. This member is only used if the **dwTypeOfBiometricDataChoice** member contains **CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE**. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_BIOMETRIC_PICTURE_TYPE** | The biometric data is a picture. |
| **CERT_BIOMETRIC_SIGNATURE_TYPE** | The biometric data is a signature. |

### `DUMMYUNIONNAME.pszObjId`

The address of a null-terminated ANSI string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the biometric data type. This member is only used if the **dwTypeOfBiometricDataChoice** member contains **CERT_BIOMETRIC_OID_DATA_CHOICE**.

### `HashedUrl`

A [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structure that contains the hashed URL of the biometric data.

## See also

[CERT_BIOMETRIC_EXT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_biometric_ext_info)