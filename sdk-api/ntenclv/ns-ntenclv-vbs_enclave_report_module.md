# VBS_ENCLAVE_REPORT_MODULE structure

## Description

Describes a module loaded for the enclave. The report contains one **VBS_ENCLAVE_REPORT_MODULE** structure for every module loaded for the enclave except the primary module for the enclave, which is described in the **EnclaveIdentity** member of the [VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report) structure.

## Members

### `Header`

The variable data header for the report.

### `UniqueId`

The enclave unique identifier of the module.

### `AuthorId`

The author identifier of the module.

### `FamilyId`

The family identifier of the module.

### `ImageId`

The image identifier of the module.

### `Svn`

The security version number of the module.

### `ModuleName`

A NULL-terminated string that contains the name of the module as it was loaded into the enclave.

## See also

[Enclave Structures](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-structures)

[VBS_ENCLAVE_REPORT](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report)

[VBS_ENCLAVE_REPORT_VARDATA_HEADER](https://learn.microsoft.com/windows/win32/api/ntenclv/ns-ntenclv-vbs_enclave_report_vardata_header)