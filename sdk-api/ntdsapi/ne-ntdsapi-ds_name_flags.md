# DS_NAME_FLAGS enumeration

## Description

The **DS_NAME_FLAGS** enumeration is used to define how the name syntax will be cracked. These flags are used by the [DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) function.

## Constants

### `DS_NAME_NO_FLAGS:0x0`

Indicates that there are no associated flags.

### `DS_NAME_FLAG_SYNTACTICAL_ONLY:0x1`

Performs a syntactical mapping at the client without transferring over the network. The only syntactic mapping supported is from [DS_FQDN_1779_NAME](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_format) to **DS_CANONICAL_NAME** or **DS_CANONICAL_NAME_EX**. [DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa) returns the **DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING** flag if a syntactical mapping is not possible.

### `DS_NAME_FLAG_EVAL_AT_DC:0x2`

Forces a trip to the domain controller for evaluation, even if the syntax could be cracked locally.

### `DS_NAME_FLAG_GCVERIFY:0x4`

The call fails if the domain controller is not a global catalog server.

### `DS_NAME_FLAG_TRUST_REFERRAL:0x8`

Enables cross forest trust referral.

## See also

[DS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_format)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)