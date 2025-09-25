## Description

Contains partition information pulled from an ETW trace. Most commonly used as a
return structure for
[QueryTraceProcessingHandle](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-querytraceprocessinghandle).

## Members

### `PartitionId`

GUID to identify the machine.

### `ParentId`

GUID that identifies the partition instance that contains the traced partition.
If the traced partition is a host, then **ParentId** will be 0.

### `QpcOffsetFromRoot`

Reserved for future use.

### `PartitionType`

Enumeration value of the container type. the value may be one of the following:

- **Process** (1): For events originating from inside a "Windows Server
Container".

- **VmHost** (2): For events originating from inside a "Hyper-V Container".

- **VmHostedUvm** (3): For events originating from a "Hyper-V Container"
template virtual machine.

- **VmDirectUvm** (4): For events originating from applications running with
[Microsoft Defender Application Guard (MDAG)](https://learn.microsoft.com/windows/security/application-security/application-isolation/microsoft-defender-application-guard/md-app-guard-overview).