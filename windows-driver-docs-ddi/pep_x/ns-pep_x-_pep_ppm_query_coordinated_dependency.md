# _PEP_PPM_QUERY_COORDINATED_DEPENDENCY structure (pep_x.h)

## Description

The **PEP_PPM_QUERY_COORDINATED_DEPENDENCY** structure describes dependencies for coordinated idle states.

## Members

### `StateIndex` [in]

The index of the coordinated idle state which is having its dependencies queried.

### `DependencyIndex` [in]

The index of the dependency being queried.

### `DependencySize` [in]

The size of the **Dependencies** array.

### `DependencySizeUsed` [out]

The number of elements of the **Dependencies** array filled in by the PEP.

### `TargetProcessor` [out]

The **POHANDLE** corresponding to the processor being targeted by this dependency, or **NULL** if this is a coordinated state dependency.

### `Options` [out]

A list of [PEP_COORDINATED_DEPENDENCY_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_coordinated_dependency_option) structures describing dependency options, one of which must be satisfied for this coordinated state to be entered.

## See also

[PEP_COORDINATED_DEPENDENCY_OPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_coordinated_dependency_option)

[PEP_NOTIFY_PPM_QUERY_COORDINATED_DEPENDENCY notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)