# NetCreateProvisioningPackage function

## Description

The
[NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function creates a provisioning package that provisions a computer account for later use in an offline domain join operation. The package may also contain information about certificates and policies to add to the machine during provisioning.

## Parameters

### `pProvisioningParams` [in]

A pointer to a [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) structure that contains information about the provisioning package.

The following values are defined for the members of this structure:

| Value | Meaning |
| --- | --- |
| **dwVersion** | The version of Windows in the provisioning package. This member should use the following value defined in the *Lmjoin.h* header file:<br><br>NETSETUP_PROVISIONING_PARAMS_CURRENT_VERSION (0x00000001) |
| **lpDomain** | A pointer to a constant null-terminated character string that specifies the name of the domain where the computer account is created. <br><br> |
| **lpMachineName** | A pointer to a constant null-terminated character string that specifies the short name of the machine from which the computer account attribute sAMAccountName is derived by appending a '$'. This parameter must contain a valid DNS or NetBIOS machine name. |
| **lpMachineAccountOU** | An optional pointer to a constant null-terminated character string that contains the RFC 1779 format name of the organizational unit (OU) where the computer account will be created. If you specify this parameter, the string must contain a full path, for example, OU=testOU,DC=domain,DC=Domain,DC=com. Otherwise, this parameter must be **NULL**.<br><br>If this parameter is **NULL**, the well known computer object container will be used as published in the domain. |
| **lpDcName** | An optional pointer to a constant null-terminated character string that contains the name of the domain controller to target. |
| **dwProvisionOptions** | A set of bit flags that define provisioning options. This parameter can be one or more of the values specified for the *dwOptions* parameter passed to the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function. <br><br>These possible values are defined in the *Lmjoin.h* header file. <br><br>The **NETSETUP_PROVISION_ROOT_CA_CERTS** option is only supported on Windows 8 and Windows Server 2012. |
| **aCertTemplateNames** | A optional pointer to an array of **NULL**-terminated certificate template names. |
| **cCertTemplateNames** | When **aCertTemplateNames** is not NULL, this member provides an explicit count of the number of items in the array. |
| **aMachinePolicyNames** | An optional pointer to an array of **NULL**-terminated machine policy names. |
| **cMachinePolicyNames** | When **aMachinePolicyNames** is not **NULL**, this member provides an explicit count of the number of items in the array. |
| **aMachinePolicyPaths** | An optional pointer to an array of character strings. Each array element is a NULL-terminated character string which specifies the full or partial path to a file in the Registry Policy File format. For more information on the Registry Policy File Format , see [Registry Policy File Format](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/registry-policy-file-format)<br><br>The path could be a UNC path on a remote server. |
| **cMachinePolicyPaths** | When **aMachinePolicyPaths** is not **NULL**, this member provides an explicit count of the number of items in the array. |

### `ppPackageBinData` [out, optional]

An optional pointer that will receive the package required by [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function to complete an offline domain join, if the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function completes successfully. The data is returned as an opaque binary buffer which may be passed to **NetRequestOfflineDomainJoin** function.

If this parameter is **NULL**, then *pPackageTextData* parameter must not be **NULL**. If this parameter is not **NULL**, then the *pPackageTextData* parameter must be **NULL**.

### `pdwPackageBinDataSize` [out, optional]

A pointer to a value that receives the size, in bytes, of the buffer returned in the *pProvisionBinData* parameter.

This parameter must not be **NULL** if the *pPackageBinData* parameter is not **NULL**. This parameter must be **NULL** when the *pPackageBinData* parameter is **NULL**.

### `ppPackageTextData` [out, optional]

An optional pointer that will receive the package required by [NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function to complete an offline domain join, if the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function completes successfully. The data is returned in string form for embedding in an unattended setup answer file.

If this parameter is **NULL**, then the *pPackageBinData* parameter must not be **NULL**. If this parameter is not **NULL**, then the *pPackageBinData* parameter must be **NULL**.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller does not have sufficient privileges to complete the operation. |
| **ERROR_INVALID_DOMAIN_ROLE** | This operation is only allowed for the Primary Domain Controller of the domain. This error is returned if a domain controller name was specified in the **lpDcName**  of the [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) struct pointed to by the *pProvisioningParams* parameter, but the computer specified could not be validated as a domain controller for the target domain specified in the **lpDomain** of the **NETSETUP_PROVISIONING_PARAMS**. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is also returned if both the *pProvisioningParams* parameter is **NULL**. This error is also returned if the **lpDomain** or **lpMachineName** member of the [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) struct pointed to by the *pProvisioningParams* parameter is **NULL**. |
| **ERROR_NO_SUCH_DOMAIN** | The specified domain did not exist. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the **lpMachineAccountOU** member was specified in the [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) struct pointed to by the *pProvisioningParams* parameter and the domain controller is running on an earlier versions of Windows that does not support this parameter. |
| **NERR_DS8DCRequired** | The specified domain controller does not meet the version requirement for this operation. |
| **NERR_LDAPCapableDCRequired** | This operation requires a domain controller which supports LDAP. |
| **NERR_UserExists** | The account already exists in the domain and the **NETSETUP_PROVISION_REUSE_ACCOUNT** bit was not specified in the **dwProvisionOptions** member of the [NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params) struct pointed to by the *pProvisioningParams* parameter. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |
| **RPC_S_CALL_IN_PROGRESS** | A remote procedure call is already in progress for this thread. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The remote procedure call protocol sequence is not supported. |

## Remarks

The **NetCreateProvisioningPackage** function is supported on Windows 8 and Windows Server 2012 for offline join operations. For Windows 7, use the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function.

The **NetCreateProvisioningPackage** function is used to provision a computer account for later use in an offline domain join operation using the [NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall) function.

The offline domain join scenario uses two functions:

* **NetCreateProvisioningPackage** is a provisioning function that is first called to perform the network operations necessary to create and configure the computer object in Active Directory. The output from the **NetCreateProvisioningPackage** is a package used for the next step.
* [NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall), an image initialization function, is called to inject the output from the **NetCreateProvisioningPackage** provisioning function into a Windows operating system image for use during pre-installation and post-installation.

Changes to Windows initialization code will detect this saved state and affect the local-only portion of domain join.

When the *pPackageBinData* and *pdwPackageBinDataSize* out pointers are used, set the *pPackageTextData* out pointer to NULL. When *pPackageTextData* is used, set the *pPackageBinData* and *pdwPackageBinDataSize* out pointers to NULL.

The *pProvisioningParams* parameter specifies data to include in the provisioning package. The package includes information relevant to the domain join, and it can also include information about policies and certificates to install on the machine. The provisioning package can be used in four ways:

* Domain join
* Domain join and installation of certificates
* Domain join and installation of policies
* Domain join and installation of certificates and policies

The **NetCreateProvisioningPackage** function creates or reuses the machine account in the domain, collects all necessary metadata and returns it in a package. The package can be consumed by the offline domain join request operation supplying all the necessary input to complete the domain join during first boot without any network operations (local state updates only).

**Security Note:** The package returned by the **NetCreateProvisioningPackage** function contains very sensitive data. It should be treated just as securely as a plaintext password. The package contains the machine account password and other information about the domain, including the domain name, the name of a domain controller, and the security ID (SID) of the domain. If the package is being transported physically or over the network, care must be taken to transport it securely. The design makes no provisions for securing this data. This problem exists today with unattended setup answer files which can carry a number of secrets including domain user passwords. The caller must secure the package. Solutions to this problem are varied. As an example, a pre-exchanged key could be used to encrypt a session between the consumer and provisioning entity enabling a secure transfer of the package.

The package returned in the *pPackageBinData* parameter by the **NetCreateProvisioningPackage** function is versioned to allow interoperability and serviceability scenarios between different versions of Windows (such as joining a client, provisioning a machine, and using a domain controller). A package created on Windows 8 or Windows Server 2012 can be used Windows 7 or Windows Server 2008 R2, however only domain join information will take effect (certificates and policies are not supported). The offline join scenario currently does not limit the lifetime of the package returned by the **NetCreateProvisioningPackage** function.

For offline domain joins, the access check performed depends on the configuration of the domain. Computer account creation is enabled using three methods:

* Domain administrators have rights to create computer accounts.
* The SD on a container can delegate the rights to create computer accounts.
* By default, authenticated users may create computer accounts by privilege. Authenticated users are limited to creating a limited number of accounts that is specified as a quota on the domain (the default value is 10). For more information, see the [ms-DS-MachineAccountQuota](https://learn.microsoft.com/openspecs/windows_protocols/ms-ada2/6ba13b0c-1620-478c-b2ae-eca041f2e1c4) attribute in the Active Directory schema.

The **NetCreateProvisioningPackage** function works only with a writable domain controller and does not function against a read-only domain controller. Once provisioning is done against a writable domain controller and the account is replicated to a read-only domain controller, the other portions of the offline domain join operation do not require access to a domain controller.

If the **NetCreateProvisioningPackage** function is successful, the pointer in the *pPackageBinData* or *pPackageTextData* parameter (depending on which parameter was not **NULL**) is returned with the serialized data for use in an offline join operation or as text in an unattended setup file.

All phases of the provisioning process append to a *NetSetup.log* file on the local computer. The provisioning process can include up to three different computers: the computer where the provisioning package is created, the computer that requests the installation of the package, and the computer where the package is installed. There will be *NetSetup.log* file information stored on all three computers according to the operation performed. Reviewing the contents of these files is the most common means of troubleshooting online and offline provisioning errors. Provisioning operations undertaken by admins are logged to the *NetSetup.log* file in the *%WINDIR%\Debug*. Provisioning operations performed by non-admins are logged to the *NetSetup.log* file in the *%USERPROFILE%\Debug* folder.

For more information on offline domain join operations, see the [Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10)).

Joining (and unjoining) a computer to a domain using [NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain) and [NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain) is performed only by a member of the Administrators local group on the target computer. Note that the domain administrator can set additional requirements for joining the domain using delegation and assignment of privileges.

## See also

[NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin)

[NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)