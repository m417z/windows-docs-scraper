# IKEEXT_CERT_NAME0 structure

## Description

The **IKEEXT_CERT_NAME0** structure specifies certificate selection "subject" criteria for an authentication method.

## Members

### `nameType`

Type: [IKEEXT_CERT_CRITERIA_NAME_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_criteria_name_type)

The type of NAME field.

### `certName`

Type: **LPWSTR**

The string to be used for matching the "subject" criteria.

## See also

[IKEEXT_CERT_CRITERIA_NAME_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cert_criteria_name_type)