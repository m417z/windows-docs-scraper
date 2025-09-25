# DS_REPL_KCC_DSA_FAILUREW_BLOB structure

## Description

The **DS_REPL_KCC_DSA_FAILUREW_BLOB** structure contains replication state data with respect to a specific inbound replication partner. This state data is compiled and used by the Knowledge Consistency Checker (KCC) to decide when alternate replication routes must be added to account for unreachable servers.
This structure is similar to the [DS_REPL_KCC_DSA_FAILURE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failurew) structure, but is obtained from the [Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) functions when obtaining binary data for the **msDS-ReplConnectionFailures** or **msDS-ReplLinkFailures** attribute.

## Members

### `oszDsaDN`

Contains the offset, in bytes, from the address of this structure to a null-terminated string that contains the distinguished name of the directory system agent object in the directory that corresponds to the source server.

### `uuidDsaObjGuid`

Contains the **objectGuid** of the directory system agent object represented by the **oszDsaDN** member.

### `ftimeFirstFailure`

Contains a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure which the contents of depends on the requested binary replication data.

#### msDS-ReplConnectionFailures

Contains the date and time that the first failure occurred when replicating from the source server.

#### msDS-ReplLinkFailures

Contains the date and time of the last successful replication.

### `cNumFailures`

Contains the number of consecutive failures since the last successful replication.

### `dwLastResult`

Contains the error code associated with the most recent failure, or **ERROR_SUCCESS** if the specific error is unavailable.

## See also

[DS_REPL_KCC_DSA_FAILURE](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_repl_kcc_dsa_failurew)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Lightweight Directory Access Protocol API](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api)