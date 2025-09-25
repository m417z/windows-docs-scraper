# NetJoinDomain function

## Description

The
**NetJoinDomain** function joins a computer to a workgroup or domain.

## Parameters

### `lpServer` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to execute the domain join operation. If this parameter is **NULL**, the local computer is used.

### `lpDomain` [in]

A pointer to a constant null-terminated character string that specifies the name of the domain or workgroup to join.

Optionally, you can specify the preferred domain controller to perform the join operation. In this instance, the string must be of the form *DomainName\MachineName*, where *DomainName* is the name of the domain to join, and *MachineName* is the name of the domain controller to perform the join.

### `lpMachineAccountOU` [in]

Optionally specifies the pointer to a constant null-terminated character string that contains the RFC 1779 format name of the organizational unit (OU) for the computer account. If you specify this parameter, the string must contain a full path, for example, OU=testOU,DC=domain,DC=Domain,DC=com. Otherwise, this parameter must be **NULL**.

### `lpAccount` [in]

A pointer to a constant null-terminated character string that specifies the account name to use when connecting to the domain controller. The string must specify either a domain NetBIOS name and user account (for example, *REDMOND\user*) or the user principal name (UPN) of the user in the form of an Internet-style login name (for example, "someone@example.com"). If this parameter is **NULL**, the caller's context is used.

### `lpPassword` [in]

If the *lpAccount* parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller. Otherwise, this parameter must be **NULL**.

You can specify a local machine account password rather than a user password for unsecured joins. For more information, see the description of the NETSETUP_MACHINE_PWD_PASSED flag described in the *fJoinOptions* parameter.

### `fJoinOptions` [in]

A set of bit flags defining the join options. This parameter can be one or more of the following values defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_JOIN_DOMAIN**<br><br>0x00000001 | Joins the computer to a domain. If this value is not specified, joins the computer to a workgroup. |
| **NETSETUP_ACCT_CREATE**<br><br>0x00000002 | Creates the account on the domain. |
| **NETSETUP_WIN9X_UPGRADE**<br><br>0x00000010 | The join operation is occurring as part of an upgrade. |
| **NETSETUP_DOMAIN_JOIN_IF_JOINED**<br><br>0x00000020 | Allows a join to a new domain even if the computer is already joined to a domain. |
| **NETSETUP_JOIN_UNSECURE**<br><br>0x00000040 | Performs an unsecured join. <br><br>This option requests a domain join to a pre-created account without authenticating with domain user credentials. This option can be used in conjunction with **NETSETUP_MACHINE_PWD_PASSED** option. In this case, *lpPassword* is the password of the pre-created machine account. <br><br>Prior to Windows Vista with SP1 and Windows Server 2008, an unsecure join did not authenticate to the domain controller. All communication was performed using a null (unauthenticated) session. Starting with Windows Vista with SP1 and Windows Server 2008, the machine account name and password are used to authenticate to the domain controller. |
| **NETSETUP_MACHINE_PWD_PASSED**<br><br>0x00000080 | Indicates that the *lpPassword* parameter specifies a local machine account password rather than a user password. This flag is valid only for unsecured joins, which you must indicate by also setting the NETSETUP_JOIN_UNSECURE flag.<br><br>If you set this flag, then after the join operation succeeds, the machine password will be set to the value of *lpPassword*, if that value is a valid machine password. |
| **NETSETUP_DEFER_SPN_SET**<br><br>0x00000100 | Indicates that the service principal name (SPN) and the DnsHostName properties on the computer object should not be updated at this time. <br><br>Typically, these properties are updated during the join operation. Instead, these properties should be updated during a subsequent call to the [NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain) function. These properties are always updated during the rename operation. For more information, see the following Remarks section. |
| **NETSETUP_JOIN_DC_ACCOUNT**<br><br>0x00000200 | Allow the domain join if existing account is a domain controller.<br><br>**Note** This flag is supported on Windows Vista and later. |
| **NETSETUP_JOIN_WITH_NEW_NAME**<br><br>0x00000400 | Join the target machine specified in *lpServer* parameter with a new name queried from the registry on the machine specified in the *lpServer* parameter. <br><br>This option is used if [SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) has been called prior to rebooting the machine. The new computer name will not take effect until a reboot. With this option, the caller instructs the **NetJoinDomain** function to use the new name during the domain join operation. A reboot is required after calling **NetJoinDomain** successfully at which time both the computer name change and domain membership change will have taken affect. <br><br>**Note** This flag is supported on Windows Vista and later. |
| **NETSETUP_JOIN_READONLY**<br><br>0x00000800 | Join the target machine specified in *lpServer* parameter using a pre-created account without requiring a writable domain controller. <br><br>This option provides the ability to join a machine to domain if an account has already been provisioned and replicated to a read-only domain controller. The target read-only domain controller is specified as part of the *lpDomain* parameter, after the domain name delimited by a ‘\’ character. This provisioning must include the machine secret. The machine account must be added via group membership into the allowed list for password replication policy, and the account password must be replicated to the read-only domain controller prior to the join operation. For more information, see the information on [Password Replication Policy Administration](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc753470(v=ws.10)).<br><br>Starting with Windows 7, an alternate mechanism is to use the offline domain join mechanism. For more information, see the **NetProvisionComputerAccount** and **NetRequestOfflineDomainJoin** functions.<br><br>**Note** This flag is supported on Windows Vista and later. |
| **NETSETUP_AMBIGUOUS_DC**<br><br>0x00001000 | When joining the domain don't try to set the preferred domain controller in the registry.<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_NO_NETLOGON_CACHE**<br><br>0x00002000 | When joining the domain don't create the Netlogon cache.<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_DONT_CONTROL_SERVICES**<br><br>0x00004000 | When joining the domain don't force Netlogon service to start.<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_SET_MACHINE_NAME**<br><br>0x00008000 | When joining the domain for offline join only, set target machine hostname and NetBIOS name.<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_FORCE_SPN_SET**<br><br>0x00010000 | When joining the domain, override other settings during domain join and set the service principal name (SPN).<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_NO_ACCT_REUSE**<br><br>0x00020000 | When joining the domain, do not reuse an existing account.<br><br>**Note** This flag is supported on Windows 7, Windows Server 2008 R2, and later. |
| **NETSETUP_IGNORE_UNSUPPORTED_FLAGS**<br><br>0x10000000 | If this bit is set, unrecognized flags will be ignored by the **NetJoinDomain** function and **NetJoinDomain** will behave as if the flags were not set. |

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller was not a member of the Administrators local group on the target computer. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *lpDomain* parameter is **NULL**. |
| **ERROR_NO_SUCH_DOMAIN** | The specified domain did not exist. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the computer specified in the *lpServer* parameter does not support some of the options passed in the *fJoinOptions* parameter. |
| **NERR_InvalidWorkgroupName** | The specified workgroup name is not valid. |
| **NERR_SetupAlreadyJoined** | The computer is already joined to a domain. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |
| **RPC_S_CALL_IN_PROGRESS** | A remote procedure call is already in progress for this thread. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The remote procedure call protocol sequence is not supported. |

## Remarks

Joining (and unjoining) a computer to a domain or workgroup can be performed only by a member of the Administrators local group on the target computer. Note that the domain administrator can set additional requirements for joining the domain using delegation and assignment of privileges.

If you call the
**NetJoinDomain** function remotely, you must supply credentials because you cannot delegate credentials under these circumstances.

Different processes, or different threads of the same process, should not call the
**NetJoinDomain** function at the same time. This situation can leave the computer in an inconsistent state.

If you encounter a problem during a join operation, you should not delete a computer account and immediately follow the deletion with another join attempt. This can lead to replication-related problems that are difficult to investigate. When you delete a computer account, wait until the change has replicated to all domain controllers before attempting another join operation.

A system reboot is required after calling the **NetJoinDomain** function for the operation to complete.

**Windows Server 2003 and Windows XP:** When a call to the
**NetJoinDomain** function precedes a call to the
[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain) function, you should defer the update of the SPN and DnsHostName properties on the computer object until the rename operation. This is because the join operation can fail in certain situations. An example of such a situation is when the SPN that is derived from the current computer name is not valid in the new domain that the computer is joining, but the SPN derived from the new name that the computer will have after the rename operation is valid in the new domain. In this situation, the call to
**NetJoinDomain** fails unless you defer the update of the two properties until the rename operation by specifying the NETSETUP_DEFER_SPN_SET flag in the *fJoinOptions* parameter when you call
**NetJoinDomain**.

## See also

[NetAddAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netaddalternatecomputername)

[NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage)

[NetEnumerateComputerNames](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netenumeratecomputernames)

[NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount)

[NetRemoveAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netremovealternatecomputername)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin)

[NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall)

[NetSetPrimaryComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netsetprimarycomputername)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10))

[Password Replication Policy Administration](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc753470(v=ws.10))