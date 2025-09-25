# CERT_PRIVATE_KEY_VALIDITY structure

## Description

The **CERT_PRIVATE_KEY_VALIDITY** structure indicates a valid time span for the private key corresponding to a certificate's public key. If the **NotBefore** component is zero or not present, no statement is made as to when the validity period of the private key begins. If the **NotAfter** component is zero or not present, no end date is set on the validity of the private key.

A **CERT_PRIVATE_KEY_VALIDITY** structure is a member of the
[CERT_KEY_ATTRIBUTES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_attributes_info) structure.

## Members

### `NotBefore`

Date and time before which the certificate is not valid. For dates between 1950 and 2049 inclusive, the date and time is encoded UTC-time in the form YYMMDDHHMMSS. This member uses a two-digit year and is precise to seconds. For dates before 1950 or after 2049, encoded generalized-time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four-digit year, and is precise to milliseconds. Even though generalized time supports millisecond resolution, the **NotBefore** time is only precise to seconds.

### `NotAfter`

Date and time after which the certificate is not valid. For dates between 1950 and 2049 inclusive, the date and time is encoded UTC-time in the form YYMMDDHHMMSS. This member uses a two-digit year and is precise to seconds. For dates before 1950 or after 2049, encoded generalized time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four digit year, and is precise to milliseconds. Even though generalized time supports millisecond resolution, the **NotAfter** time is only precise to seconds.

## See also

[CERT_KEY_ATTRIBUTES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_attributes_info)