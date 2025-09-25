# FsRtlInitializeExtraCreateParameter function

## Description

The **FsRtlInitializeExtraCreateParameter** routine initializes an extra create parameter (ECP) context structure.

## Parameters

### `Ecp` [in]

Pointer to the ECP context structure to initialize.

### `EcpFlags` [in]

Defines initialization options. Currently, no flags are defined.

### `CleanupCallback` [in, optional]

Optional pointer to a filter-defined cleanup callback routine of type [PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85)). The cleanup callback routine is called when the ECP context structure (created by the [FsRtlAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter) routine) is deleted. Set this parameter to **NULL** if a cleanup callback routine is not applicable.

### `TotalSize` [in]

The size, in bytes, of the ECP context structure to initialize.

### `EcpType` [in]

Pointer to a GUID that indicates the type of ECP for which the context structure will be initialized. For more information about ECPs, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-extra-create-parameters-with-an-irp-mj-create-operation).

### `ListAllocatedFrom` [in, optional]

Optional pointer to the list from which the ECP context structure is allocated.

## See also

[FsRtlAllocateExtraCreateParameter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlallocateextracreateparameter)

[PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK](https://learn.microsoft.com/previous-versions/ff551124(v=vs.85))