# DS_SPN_WRITE_OP enumeration

## Description

The **DS_SPN_WRITE_OP** enumeration identifies the type of write operation that should be performed by the [DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna) function.

## Constants

### `DS_SPN_ADD_SPN_OP:0`

Adds the specified service principal names (SPNs) to the object identified by the *pszAccount* parameter in [DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna).

### `DS_SPN_REPLACE_SPN_OP:1`

Removes all SPNs currently registered on the account identified by the *pszAccount* parameter in [DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna) and replaces them with the SPNs specified by the *rpszSpn* parameter in **DsWriteAccountSpn**.

### `DS_SPN_DELETE_SPN_OP:2`

Deletes the specified SPNs from the object identified by the *pszAccount* parameter in [DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna).

## See also

[DsWriteAccountSpn](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dswriteaccountspna)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)