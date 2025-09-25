## Description

The **NETSETUP_PROVISIONING_PARAMS** structure contains information that is used when creating a provisioning package using the [NetCreateProvisionPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function.

## Members

### `dwVersion`

The version of Windows in the provisioning package. This parameter should use the following value defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_PROVISIONING_PARAMS_CURRENT_VERSION**<br><br>0x00000001 | The version for this package is Windows Server 2012. |

### `lpDomain`

A pointer to a **NULL**-terminated character string that specifies the name of the domain where the computer account is created.

### `lpHostName`

A pointer to a **NULL**-terminated character string that specifies the short name of the machine from which the computer account attribute sAMAccountName is derived by appending a '$'. This parameter must contain a valid DNS or NetBIOS machine name.

### `lpMachineAccountOU`

A optional pointer to a **NULL**-terminated character string that contains the RFC 1779 format name of the organizational unit (OU) where the computer account will be created. If you specify this parameter, the string must contain a full path, for example, OU=testOU,DC=domain,DC=Domain,DC=com. Otherwise, this parameter must be **NULL**.

If this parameter is **NULL**, the well known computer object container will be used as published in the domain.

### `lpDcName`

An optional pointer to a **NULL**-terminated character string that contains the name of the domain controller to target.

### `dwProvisionOptions`

A set of bit flags that define provisioning options. This parameter can be one or more of the following values defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT**<br><br>0x00000001 | If the caller requires account creation by privilege, this option will cause a retry on failure using account creation functions enabling interoperability with domain controllers running on earlier versions of Windows. <br><br>The *lpMachineAccountOU* is not supported when using downlevel privilege support. |
| **NETSETUP_PROVISION_REUSE_ACCOUNT**<br><br>0x00000002 | If the named account already exists, an attempt will be made to reuse the existing account. <br><br>This option requires sufficient credentials for this operation (Domain Administrator or the object owner). |
| **NETSETUP_PROVISION_USE_DEFAULT_PASSWORD**<br><br>0x00000004 | Use the default machine account password which is the machine name in lowercase. This is largely to support the older unsecure join model where the pre-created account typically used this default password. |
| **NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH**<br><br>0x00000008 | Do not try to find the account on any domain controller in the domain. This option makes the operation faster, but should only be used when the caller is certain that an account by the same name hasn't recently been created. <br><br>This option is only valid when the *lpDcName* parameter is specified. When the prerequisites are met, this option allows for must faster provisioning useful for scenarios such as batch processing. |
| **NETSETUP_PROVISION_ROOT_CA_CERTS**<br><br>0x00000010 | This option retrieves all of the root Certificate Authority certificates on the local machine and adds them to the provisioning package.<br><br>**Note** This flag is only supported by the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function on Windows 8, Windows Server 2012, and later. |

### `aCertTemplateNames`

A pointer to an array of **NULL**-terminated certificate template names.

### `cCertTemplateNames`

When **aCertTemplateNames** is not **NULL**, this member provides an explicit count of the number of items in the array.

### `aMachinePolicyNames`

A pointer to an array of **NULL**-terminated machine policy names.

### `cMachinePolicyNames`

When **aMachinePolicyNames** is not **NULL**, this member provides an explicit count of the number of items in the array.

### `aMachinePolicyPaths`

A pointer to an array of character strings. Each array element is a NULL-terminated character string which specifies the full or partial path to a file in the Registry Policy File format. For more information on the Registry Policy File Format , see [Registry Policy File Format](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/registry-policy-file-format)

This path could be a UNC path on a remote server.

### `cMachinePolicyPaths`

When **aMachinePolicyPaths** is not **NULL**, this member provides an explicit count of the number of items in the array.

### `lpNetbiosName`

TBD

### `lpSiteName`

TBD

### `lpPrimaryDNSDomain`

TBD
## Remarks

The **NETSETUP_PROVISIONING_PARAMS** structure provides flags for the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function which is supported on Windows 8 and Windows Server 2012 for offline join operations.

In addition to domain joins, the provisioning package can provide certificates and policies to the machine. The provisioning package can be used in four ways:

* Domain join
* Domain join and installation of certificates
* Domain join and installation of policies
* Domain join and installation of certificates and policies

When certificates need to be added to the package, this structure provides the **aCertTemplateNames** member as an array of **NULL**-terminated certificate template names. The **aCertTemplateNames** member requires the **cCertTemplateNames** member to provide an explicit count of the number of items in the array.

There are two different ways to add policies. You can use one or both methods:

* Policy name—An array of **NULL**-terminated policy names is provided in the **aMachinePolicyNames** member. During runtime, the policy name is mapped to the policy name in AD and the GUID that represents the policy in the enterprise space is retrieved. The **aMachinePolicyNames** member requires the **cMachinePolicyNames** member to provide an explicit count of the number of items in the array.
* Policy path—A pointer to an array of **NULL**-terminated character strings provided in the **aMachinePolicyPaths** member which specify the path to a file in the Registry Policy File format. For more information on the Registry Policy File Format , see [Registry Policy File Format](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/registry-policy-file-format). The policy path is a full or relative path to the policy file.

## See also

[NetCreateProvisionPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin)

[NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)