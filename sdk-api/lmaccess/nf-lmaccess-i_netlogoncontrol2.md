# I_NetLogonControl2 function

## Description

The **I_NetLogonControl2** function controls various aspects of the Netlogon service.

## Parameters

### `ServerName` [in, optional]

The name of the remote server.

### `FunctionCode` [in]

The operation to be performed. This value can be one of the following.

| Value | Meaning |
| --- | --- |
| **NETLOGON_CONTROL_QUERY**<br><br>1 | No operation. Returns only the requested information. |
| **NETLOGON_CONTROL_REPLICATE**<br><br>2 | Forces the security account manager (SAM) database on a backup domain controller (BDC) to be brought in sync with the copy on the primary domain controller (PDC). This operation does not imply a full synchronize. The Netlogon service replicates any outstanding differences if possible. |
| **NETLOGON_CONTROL_SYNCHRONIZE**<br><br>3 | Forces a BDC to get a new copy of the SAM database from the PDC. This operation performs a full synchronize. |
| **NETLOGON_CONTROL_PDC_REPLICATE**<br><br>4 | Forces a PDC to ask for each BDC to replicate now. |
| **NETLOGON_CONTROL_REDISCOVER**<br><br>5 | Forces a domain controller (DC) to rediscover the specified trusted domain DC. |
| **NETLOGON_CONTROL_TC_QUERY**<br><br>6 | Queries the secure channel, requesting a status update about its last usage. |
| **NETLOGON_CONTROL_TC_VERIFY**<br><br>10 | Verifies the current status of the specified trusted domain secure channel. If the status indicates success, the domain controller is pinged. If the status or the ping indicates failure, a new trusted domain controller is rediscovered. |
| **NETLOGON_CONTROL_CHANGE_PASSWORD**<br><br>9 | Forces a password change on a secure channel to a trusted domain. |
| **NETLOGON_CONTROL_FORCE_DNS_REG**<br><br>11 | Forces the domain controller to re-register all of its DNS records. The *QueryLevel* parameter must be set to 1. |
| **NETLOGON_CONTROL_QUERY_DNS_REG**<br><br>12 | Issues a query requesting the status of DNS updates performed by the Netlogon service. If any DNS registration or deregistration errors occurred on the last update, the result is negative. The *QueryLevel* parameter must be set to 1. |

### `QueryLevel` [in]

Indicates what information should be returned from the Netlogon service. This value can be any of the following structures.

#### NETLOGON_INFO_1 (1)

#### NETLOGON_INFO_2 (2)

#### NETLOGON_INFO_3 (3)

#### NETLOGON_INFO_4 (4)

### `Data` [in]

Carries input data that depends on the value specified in the *FunctionCode* parameter. The NETLOGON_CONTROL_REDISCOVER and NETLOGON_CONTROL_TC_QUERY function codes specify the trusted domain name (the data type is **LPWSTR ***).

### `Buffer` [out]

Returns a pointer to a buffer that contains the requested information in the structure passed in the *QueryLevel* parameter.

 The buffer must be freed using [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

## Return value

The method returns 0x00000000 (**NERR_Success**) on success; otherwise, it returns a nonzero error code defined in Lmerr.h or Winerror.h. NET_API_STATUS error codes begin with the value 0x00000834. For more information about network management error codes, see [Network_Management_Error_Codes](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-error-codes). The following table describes possible return values.

| Return code/value | Description |
| --- | --- |
| **NERR_Success**<br><br>0x00000000 | The method call completed without errors. |
| **ERROR_ACCESS_DENIED**<br><br>0x00000005 | Access validation on the caller returns false. Access is denied. |
| **ERROR_NOT_ENOUGH_MEMORY**<br><br>0x00000008 | Not enough storage is available to process this command. |
| **ERROR_NOT_SUPPORTED**<br><br>0x00000032 | A function code is not valid on the specified server. For example, NETLOGON_CONTROL_REPLICATE might have been passed to a primary domain controller (PDC). |
| **ERROR_INVALID_PARAMETER**<br><br>0x00000057 | A parameter is incorrect. |
| **ERROR_INVALID_LEVEL**<br><br>0x0000007C | The query call level is not correct. |
| **ERROR_SERVICE_NOT_ACTIVE**<br><br>0x000004261210121 | The service has not been started. |
| **ERROR_INVALID_COMPUTERNAME**<br><br>0x000004BA | The format of the specified computer name is invalid. |
| **ERROR_NO_LOGON_SERVERS**<br><br>0x0000051F | There are currently no logon servers available to service the logon request. |
| **ERROR_INVALID_DOMAIN_ROLE**<br><br>0x0000054A | Password change for an interdomain trust account was attempted on a backup domain controller (BDC). This operation is only allowed for the PDC of the domain. |
| **ERROR_NO_SUCH_DOMAIN**<br><br>0x0000054B | The specified domain either does not exist or could not be contacted. |
| **NERR_UserNotFound**<br><br>0x000008AD | The user name could not be found. |

## Remarks

This function can be used to request that a BDC ensure that its copy of the SAM database is brought up-to-date. It can also be used to determine if a BDC currently has a secure channel open to the PDC.

## See also

[NETLOGON_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-netlogon_info_1)

[NETLOGON_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-netlogon_info_2)

[NETLOGON_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-netlogon_info_3)

[NETLOGON_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-netlogon_info_4)