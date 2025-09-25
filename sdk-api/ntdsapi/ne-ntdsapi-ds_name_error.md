# DS_NAME_ERROR enumeration

## Description

The **DS_NAME_ERROR** enumeration defines the errors returned by the **status** member of the [DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema) structure. These are potential errors that may be encountered while a name is converted by the [DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function.

## Constants

### `DS_NAME_NO_ERROR:0`

The conversion was successful.

### `DS_NAME_ERROR_RESOLVING:1`

A generic processing error occurred.

### `DS_NAME_ERROR_NOT_FOUND:2`

The name cannot be found or the caller does not have permission to access the name.

### `DS_NAME_ERROR_NOT_UNIQUE:3`

The input name is mapped to more than one output name or the desired format did not have a single, unique value for the object found.

### `DS_NAME_ERROR_NO_MAPPING:4`

The input name was found, but the associated output format cannot be found. This can occur if the object does not have all the required attributes.

### `DS_NAME_ERROR_DOMAIN_ONLY:5`

Unable to resolve entire name, but was able to determine in which domain object resides. The caller is expected to retry the call at a domain controller for the specified domain. The entire name cannot be resolved, but the domain that the object resides in could be determined. The **pDomain** member of the [DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema) contains valid data when this error is specified.

### `DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING:6`

A syntactical mapping cannot be performed on the client without transmitting over the network.

### `DS_NAME_ERROR_TRUST_REFERRAL:7`

The name is from an external trusted forest.

## See also

[DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)