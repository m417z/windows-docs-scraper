# NetRequestOfflineDomainJoin function

## Description

The
**NetRequestOfflineDomainJoin** function executes locally on a machine to modify a Windows operating system image mounted on a volume. The registry is loaded from the image and provisioning blob data is written where it can be retrieved during the completion phase of an offline domain join operation.

## Parameters

### `pProvisionBinData` [in]

A pointer to a buffer required to initialize the registry of a Windows operating system image to process the final local state change during the completion phase of the offline domain join operation.

The opaque binary blob of serialized metadata passed in the *pProvisionBinData* parameter is returned by the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function.

### `cbProvisionBinDataSize` [in]

The size, in bytes, of the buffer pointed to by the *pProvisionBinData* parameter.

This parameter must not be **NULL**.

### `dwOptions` [in]

A set of bit flags that define options for this function. This parameter can be one or more of the following values defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NETSETUP_PROVISION_ONLINE_CALLER**<br><br>0x40000000 | This flag is required if the *lpWindowsPath* parameter references the currently running Windows operating system directory rather than an offline Windows operating system image mounted on an accessible volume. If this flag is specified, the **NetRequestOfflineDomainJoin** function must be invoked by a member of the local Administrators group. |

### `lpWindowsPath` [in]

A pointer to a constant null-terminated character string that specifies the path to a Windows operating system image under which the registry hives are located. This image must be offline and not currently booted unless the *dwOptions* parameter contains **NETSETUP_PROVISION_ONLINE_CALLER** in which case the locally running operating system directory is allowed.

This path could
be a UNC path on a remote server.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller does not have sufficient privileges to complete the operation. |
| **ERROR_ELEVATION_REQUIRED** | The requested operation requires elevation. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *pProvisionBinData*, *cbProvisionBinDataSize*, or *lpWindowsPath* parameters are **NULL**. This error is also returned if the buffer pointed to by the *pProvisionBinData* parameter does not contain valid data in the blob for the domain, machine account name, or machine account password. This error is also returned if the string pointed to *lpWindowsPath* parameter does not specific the path to a Windows operating system image. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the specified server does not support this operation. For example, if the *lpWindowsPath* parameter references a Windows installation configured as a domain controller. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |

## Remarks

The **NetRequestOfflineDomainJoin** function is supported on Windows 7 for offline domain join operations.

The
**NetRequestOfflineDomainJoin** function is used locally on a machine to modify a Windows operating system image mounted on a volume. The registry is loaded for the image and provisioning blob data is written where it can be retrieved during the completion phase of an offline domain join operation. The offline domain join scenario uses these functions as follows:

* [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) is a provisioning function that is first called to perform the network operations necessary to create and configure the computer object in Active Directory. The output from the **NetProvisionComputerAccount** is an opaque binary blob of serialized metadata used for the next step.
* **NetRequestOfflineDomainJoin** , an image initialization function, is then called to inject the output from the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) provisioning function into a Windows operating system image to be used during installation. Changes to Windows initialization code will detect this saved state and affect the local only portion of domain join.

The [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function will create or reuse the machine account in the domain, collect all necessary metadata and return it in an opaque versioned binary blob or as text for embedding in an unattended setup answer file. The opaque binary blob can be consumed by the offline domain join request operation supplying all the necessary input to complete the domain join during first boot without any network operations (local state updates only). Note that the blob contains machine account password material essentially in the clear. The design makes no provisions for securing this data. This problem exists today with unattended setup answer files which can carry a number of secrets including domain user passwords. The caller must secure the blob and the unattended setup files. Solutions to this problem are varied. As an example, a pre-exchanged key could be used to encrypt a session between the consumer and provisioning entity enabling a secure transfer of the opaque blob .

The opaque blob returned in the *pProvisionBinData* parameter by the [NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount) function is versioned to allow interoperability and serviceability scenarios between different versions of Windows (joining client, provisioning machine, and domain controller). The offline join scenario currently does not limit the lifetime of the blob returned by the **NetProvisionComputerAccount** function.

For more information on offline domain join operations, see the [Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10)).

## See also

[NetCreateProvisioningPackage](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netcreateprovisioningpackage)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetProvisionComputerAccount](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netprovisioncomputeraccount)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetRequestProvisioningPackageInstall](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrequestprovisioningpackageinstall)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Offline Domain Join Step-by-Step Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/dd392267(v=ws.10))