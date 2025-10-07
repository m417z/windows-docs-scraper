# CAPICOM\_CERTIFICATE\_SAVE\_AS\_TYPE enumeration

The **CAPICOM\_CERTIFICATE\_SAVE\_AS\_TYPE** enumeration type defines the format of a file containing certificate information. This enumeration type was introduced by CAPICOM 2.0.

## Members

| Member | Description | Value |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_CERTIFICATE\_SAVE\_AS\_PFX** | The output file will be formatted as a PFX (PKCS 12) file and any associated private keys which are exportable will also be saved.<br> | 0 |
| **CAPICOM\_CERTIFICATE\_SAVE\_AS\_CER** | The output file will be formatted as a CER file with no private keys saved.<br> | 1 |

## Remarks

The **CAPICOM\_CERTIFICATE\_SAVE\_AS\_TYPE** enumeration type is used by the [**Certificate.Save**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-save) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

