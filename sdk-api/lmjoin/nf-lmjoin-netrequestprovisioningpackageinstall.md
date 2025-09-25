# NetRequestProvisioningPackageInstall function

## Description

The
**NetRequestProvisioningPackageInstall** function executes locally on a machine to modify a Windows operating system image mounted on a volume. The registry is loaded from the image and provisioning package data is written where it can be retrieved during the completion phase of an offline domain join operation.

## Parameters

### `pPackageBinData` [in]

A pointer to a buffer required to initialize the registry of a Windows operating system image to process the final local state change during the completion phase of the offline domain join operation.

The opaque binary blob of serialized metadata passed in the *pPackageBinData* parameter is returned by the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function.

### `dwPackageBinDataSize` [in]

The size, in bytes, of the buffer pointed to by the *pPackageBinData* parameter.

This parameter must not be **NULL**.

### `dwProvisionOptions` [in]

A set of bit flags that define options for this function. This parameter uses one or more of the following values defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_PROVISION_ONLINE_CALLER**<br><br>0x40000000 | This flag is required if the *lpWindowsPath* parameter references the currently running Windows operating system directory rather than an offline Windows operating system image mounted on an accessible volume. If this flag is specified, the **NetRequestProvisioningPackageInstall** function must be invoked by a member of the local Administrators group. |

### `lpWindowsPath` [in]

A pointer to a **NULL**-terminated character string that specifies the path to a Windows operating system image under which the registry hives are located. This image must be offline and not currently booted unless the *dwProvisionOptions* parameter contains **NETSETUP_PROVISION_ONLINE_CALLER**, in which case, the locally running operating system directory is allowed.

This path could
be a UNC path on a remote server.

### `pvReserved`

Reserved for future use.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following [Network Management error codes](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-error-codes).

| Return code | Description |
| --- | --- |
| **NERR_NoOfflineJoinInfo** | The offline join completion information was not found. |
| **NERR_BadOfflineJoinInfo** | The offline join completion information was bad. |
| **NERR_CantCreateJoinInfo** | Unable to create offline join information. Please ensure you have access to the specified path location and permissions to modify its contents. Running as an elevated administrator may be required. |
| **NERR_BadDomainJoinInfo** | The domain join info being saved was incomplete or bad. |
| **NERR_JoinPerformedMustRestart** | Offline join operation successfully completed but a restart is needed. |
| **NERR_NoJoinPending** | There was no offline join operation pending. |
| **NERR_ValuesNotSet** | Unable to set one or more requested machine or domain name values on the local computer. |
| **NERR_CantVerifyHostname** | Could not verify the current machine's hostname against the saved value in the join completion information. |
| **NERR_CantLoadOfflineHive** | Unable to load the specified offline registry hive. Please ensure you have access to the specified path location and permissions to modify its contents. Running as an elevated administrator may be required. |
| **NERR_ConnectionInsecure** | The minimum session security requirements for this operation were not met. |
| **NERR_ProvisioningBlobUnsupported** | Computer account provisioning blob version is not supported. |

## Remarks

The [NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin) function is supported on Windows 8 for offline domain join operations. For Windows 7, use **NetRequestOfflineDomainJoin**.

The offline domain join scenario uses two functions:

* [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) is a provisioning function that is first called to perform the network operations necessary to create and configure the computer object in Active Directory. The output from the **NetCreateProvisioningPackage** is a package used for the next step.
* **NetRequestProvisioningPackageInstall**, an image initialization function, is called to inject the output from the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) provisioning function into a Windows operating system image for use during installation.

Changes to Windows initialization code will detect this saved state and affect the local-only portion of domain join and install any certificate and policy information that may have been present in the package.

The [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function will create or reuse the machine account in the domain, collect all necessary metadata and return it in a package. The package can be consumed by the offline domain join request operation supplying all the necessary input to complete the domain join during first boot without any network operations (local state updates only).

**Security Note:** The package created by the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function contains very sensitive data. It should be treated just as securely as a plaintext password. The package contains the machine account password and other information about the domain, including the domain name, the name of a domain controller, and the security ID (SID) of the domain. If the package is being transported physically or over the network, care must be taken to transport it securely. The design makes no provisions for securing this data. This problem exists today with unattended setup answer files which can carry a number of secrets including domain user passwords. The caller must secure the package. Solutions to this problem are varied. As an example, a pre-exchanged key could be used to encrypt a session between the consumer and provisioning entity enabling a secure transfer of the package.

The package returned in the *pPackageBinData* parameter by the [NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage) function is versioned to allow interoperability and serviceability scenarios between different versions of Windows (such as joining a client, provisioning a machine, and using a domain controller). The offline join scenario currently does not limit the lifetime of the package returned by the **NetCreateProvisioningPackage** function.

All phases of the provisioning process append to a *NetSetup.log* file on the local computer. The provisioning process can include up to three different computers: the computer where the provisioning package is created, the computer that requests the installation of the package, and the computer where the package is installed. There will be *NetSetup.log* file information stored on all three computers according to the operation performed. Reviewing the contents of these files is the most common means of troubleshooting online and offline provisioning errors. Provisioning operations undertaken by admins are logged to the *NetSetup.log* file in the *%WINDIR%\Debug*. Provisioning operations performed by non-admins are logged to the *NetSetup.log* file in the *%USERPROFILE%\Debug* folder.

## See also

[NETSETUP_PROVISIONING_PARAMS](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-netsetup_provisioning_params)

[NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

**NetProvisionComputerAccount**

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestOfflineDomainJoin](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestofflinedomainjoin)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)