# KERB_CERTIFICATE_INFO structure

## Description

The **KERB_CERTIFICATE_INFO** structure contains the certificate information.

## Members

### `CertInfoSize`

The size, in bytes, of the **KERB_CERTIFICATE_INFO** structure including the marshaled payload which is a structure of type specified in the *InfoType* parameter and immediately follows the **KERB_CERTIFICATE_INFO** structure in contiguous memory.

### `InfoType`

A value of the [KERB_CERTIFICATE_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_certificate_info_type) enumeration that specifies the type of certificate information that is provided.