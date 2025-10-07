# CAPICOM\_CERTIFICATES\_SAVE\_AS\_TYPE enumeration

The **CAPICOM\_CERTIFICATES\_SAVE\_AS\_TYPE** enumeration type defines the format of a file containing certificates information. This enumeration type was introduced by CAPICOM 2.0.

## Members

| Member | Description | Value |
|-------------------------------------------------|------------------------------------------------------|-------|
| **CAPICOM\_CERTIFICATES\_SAVE\_AS\_SERIALIZED** | The saved certificates are serialized.<br> | 0 |
| **CAPICOM\_CERTIFICATES\_SAVE\_AS\_PKCS7** | The certificates are saved as a PKCS \#7.<br> | 1 |
| **CAPICOM\_CERTIFICATES\_SAVE\_AS\_PFX** | The certificates are saved as a PFX.<br> | 2 |

## Remarks

The CAPICOM\_CERTIFICATES\_SAVE\_AS\_TYPE enumeration type is used by the [**Certificates.Save**](https://learn.microsoft.com/windows/win32/seccrypto/certificates-save) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

