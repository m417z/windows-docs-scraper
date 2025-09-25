# MmProtectMdlSystemAddress function

## Description

The **MmProtectMdlSystemAddress** routine sets the protection type for a memory address range.

## Parameters

### `MemoryDescriptorList` [in]

Specifies the memory address range to set the protection type for.

### `NewProtect` [in]

Specifies the new protection setting for the memory pages. Drivers should specify one of the following values:

#### PAGE_NOACCESS

The underlying memory pages cannot be read or written.

#### PAGE_READONLY

The underlying memory pages can only be read, not written.

#### PAGE_READWRITE

The underlying memory pages can be read or written.

#### PAGE_EXECUTE

The underlying memory pages can be executed, but not read or written.

#### PAGE_EXECUTE_READ

The underlying memory pages can be executed or read, but not written.

#### PAGE_EXECUTE_READWRITE

The underlying memory pages can be executed, read, or written.

## Return value

**MmProtectMdlSystemAddress** returns an NTSTATUS code. The possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully changed the protection type for the memory address range. |
| **STATUS_INVALID_PAGE_PROTECTION** | The value specified for *NewProtect* is not a valid one for this routine. |
| **STATUS_NOT_MAPPED_VIEW** | The MDL has not yet been mapped. **MmProtectMdlSystemAddress** can only be used on MDLs that have already been mapped. |

## Remarks

The **MmProtectMdlSystemAddress** routine can only be called on an MDL that has already been mapped. For example, the routine can be called on an MDL mapped by [MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache).

## See also

[MmMapLockedPagesSpecifyCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpagesspecifycache)