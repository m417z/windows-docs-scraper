# NetProvisionComputerAccount function

## Description

The
**NetProvisionComputerAccount** function provisions a computer account for later use in an offline domain join operation.

## Parameters

### `lpDomain` [in]

A pointer to a **NULL**-terminated character string that specifies the name of the domain where the computer account is created.

### `lpMachineName` [in]

A pointer to a **NULL**-terminated character string that specifies the short name of the machine from which the computer account attribute sAMAccountName is derived by appending a '$'. This parameter must contain a valid DNS or NetBIOS machine name.

### `lpMachineAccountOU` [in, optional]

An optional pointer to a **NULL**-terminated character string that contains the RFC 1779 format name of the organizational unit (OU) where the computer account will be created. If you specify this parameter, the string must contain a full path, for example, OU=testOU,DC=domain,DC=Domain,DC=com. Otherwise, this parameter must be **NULL**.

If this parameter is **NULL**, the well known computer object container will be used as published in the domain.

### `lpDcName` [in, optional]

An optional pointer to a **NULL**-terminated character string that contains the name of the domain controller to target.

### `dwOptions` [in]

A set of bit flags that define provisioning options. This parameter can be one or more of the following values defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT**<br><br>0x00000001 | If the caller requires account creation by privilege, this option will cause a retry on failure using account creation functions enabling interoperability with domain controllers running on earlier versions of Windows. <br><br>The *lpMachineAccountOU* is not supported when using downlevel privilege support. |
| **NETSETUP_PROVISION_REUSE_ACCOUNT**<br><br>0x00000002 | If the named account already exists, an attempt will be made to reuse the existing account. <br><br>This option requires sufficient credentials for this operation (Domain Administrator or the object owner). |
| **NETSETUP_PROVISION_USE_DEFAULT_PASSWORD**<br><br>0x00000004 | Use the default machine account password which is the machine name in lowercase. This is largely to support the older unsecure join model where the pre-created account typically used this default password. <br><br>**Note** Applications should avoid using this option if possible. This option as well as [NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain) function with dwOptions set to NETSETUP_JOIN_UNSECURE for unsecure join should only be used on earlier versions of Windows. |
| **NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH**<br><br>0x00000008 | Do not try to find the account on any domain controller in the domain. This option makes the operation faster, but should only be used when the caller is certain that an account by the same name hasn't recently been created. <br><br>This option is only valid when the *lpDcName* parameter is specified. When the prerequisites are met, this option allows for must faster provisioning useful for scenarios such as batch processing. |
| **NETSETUP_PROVISION_ROOT_CA_CERTS**<br><br>0x00000010 | This option retrieves all of the root Certificate Authority certificates on the local machine and adds them to the provisioning package when no certificate template names are provided as part of the provisioning package (the **aCertTemplateNames** member of the [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) struct passed in the *pProvisioningParams* parameter to the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function is NULL).<br><br>**Note** This flag is only supported by the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function on Windows 8, Windows Server 2012, and later. |

### `pProvisionBinData` [out, optional]

An optional pointer that will receive the opaque binary blob of serialized metadata required by [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function to complete an offline domain join, if the **NetProvisionComputerAccount** function completes successfully. The data is returned as an opaque binary buffer which may be passed to **NetRequestOfflineDomainJoin** function.

If this parameter is **NULL**, then *pProvisionTextData* parameter must not be **NULL**. If this parameter is not **NULL**, then the *pProvisionTextData* parameter must be **NULL**.

### `pdwProvisionBinDataSize` [out, optional]

A pointer to a value that receives the size, in bytes, of the buffer returned in the *pProvisionBinData* parameter.

This parameter must not be **NULL** if the *pProvisionBinData* parameter is not **NULL**. This parameter must be **NULL** when the *pProvisionBinData* parameter is **NULL**.

### `pProvisionTextData` [out, optional]

An optional pointer that will receive the opaque binary blob of serialized metadata required by [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function to complete an offline domain join, if the **NetProvisionComputerAccount** function completes successfully. The data is returned in string form for embedding in an unattended setup answer file.

If this parameter is **NULL**, then the *pProvisionBinData* parameter must not be **NULL**. If this parameter is not **NULL**, then the *pProvisionBinData* parameter must be **NULL**.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller does not have sufficient privileges to complete the operation. |
| **ERROR_INVALID_DOMAIN_ROLE** | This operation is only allowed for the Primary Domain Controller of the domain. This error is returned if a domain controller name was specified in the *lpDcName* parameter, but the computer specified could not be validated as a domain controller for the target domain specified in the *lpDomain* parameter. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *lpDomain* or *lpMachineName* parameter is **NULL**. This error is also returned if both the *pProvisionBinData* and *pProvisionTextData* parameters are **NULL**. |
| **ERROR_NO_SUCH_DOMAIN** | The specified domain did not exist. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the *lpMachineAccountOU* parameter was specified and the domain controller is running on an earlier versions of Windows that does not support this parameter. |
| **NERR_DS8DCRequired** | The specified domain controller does not meet the version requirement for this operation. |
| **NERR_LDAPCapableDCRequired** | This operation requires a domain controller which supports LDAP. |
| **NERR_UserExists** | The account already exists in the domain and the NETSETUP_PROVISION_REUSE_ACCOUNT bit was not specified in the *dwOptions* parameter. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |
| **RPC_S_CALL_IN_PROGRESS** | A remote procedure call is already in progress for this thread. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The remote procedure call protocol sequence is not supported. |

## Remarks

The **NetProvisionComputerAccount** function is supported on Windows 7 and Windows Server 2008 R2 for offline join operations. On Windows 8 or Windows Server 2008 R2, it is recommended that the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function be used instead of the **NetProvisionComputerAccount** function.

The **NetProvisionComputerAccount** function is used to provision a computer account for later use in an offline domain join operation using the [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function. The offline domain join scenario uses these functions as follows:

* **NetProvisionComputerAccount** is a provisioning function that is first called to perform the network operations necessary to create and configure the computer object in Active Directory. The output from the **NetProvisionComputerAccount** is an opaque binary blob of serialized metadata used for the next step.
* [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin), an image initialization function, is then called to inject the output from the **NetProvisionComputerAccount** provisioning function into a Windows operating system image to be used during installation.

Changes to Windows initialization code will detect this saved state and affect the local only portion of domain join.

The **NetProvisionComputerAccount** function will create or reuse the machine account in the domain, collect all necessary metadata and return it in an opaque versioned binary blob or as text for embedding in an unattended setup answer file. The opaque binary blob can be consumed by the offline domain join request operation supplying all the necessary input to complete the domain join during first boot without any network operations (local state updates only).

**Security Note:** The blob returned by the **NetProvisionComputerAccount** function contains very sensitive data. It should be treated just as securely as a plaintext password. The blob contains the machine account password and other information about the domain, including the domain name, the name of a domain controller, and the security ID (SID) of the domain. If the blob is being transported physically or over the network, care must be taken to transport it securely. The design makes no provisions for securing this data. This problem exists today with unattended setup answer files which can carry a number of secrets including domain user passwords. The caller must secure the blob and the unattended setup files. Solutions to this problem are varied. As an example, a pre-exchanged key could be used to encrypt a session between the consumer and provisioning entity enabling a secure transfer of the opaque blob.

The opaque blob returned in the *pProvisionBinData* parameter by the **NetProvisionComputerAccount** function is versioned to allow interoperability and serviceability scenarios between different versions of Windows (joining client, provisioning machine, and domain controller). The offline join scenario currently does not limit the lifetime of the blob returned by the **NetProvisionComputerAccount** function.

For offline domain joins, the access check performed depends on the configuration of the domain. Computer account creation is enabled using three methods:

* Domain administrators have rights to create computer accounts.
* The SD on a container can delegate the rights to create computer accounts.
* By default, authenticated users may create computer accounts by privilege. Authenticated users are limited to creating a limited number of accounts that is specified as a quota on the domain (the default value is 10). For more information, see the [ms-DS-MachineAccountQuota](https://learn.microsoft.com/openspecs/windows_protocols/ms-ada2/6ba13b0c-1620-478c-b2ae-eca041f2e1c4) attribute in the Active Directory schema.

The **NetProvisionComputerAccount** function works only with a writable domain controller and does not function against a read-only domain controller. Once provisioning is done against a writable domain controller and the account is replicated to a read-only domain controller, then the other portions of offline domain join operation do not require access to a domain controller.

If the **NetProvisionComputerAccount** function is successful, the pointer in the *pProvisionBinData* or *pProvisionTextData* parameter (depending on which was parameter was not **NULL**) is returned with the serialized data for use in an offline join operation or as text in an unattended setup file.

For more information on offline domain join operations, see the [Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10)).

Joining (and unjoining) a computer to a domain using [NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain) and [NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain) can be performed only by a member of the Administrators local group on the target computer. Note that the domain administrator can set additional requirements for joining the domain using delegation and assignment of privileges.

## See also

[NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10))

[ms-DS-MachineAccountQuota](https://learn.microsoft.com/openspecs/windows_protocols/ms-ada2/6ba13b0c-1620-478c-b2ae-eca041f2e1c4)