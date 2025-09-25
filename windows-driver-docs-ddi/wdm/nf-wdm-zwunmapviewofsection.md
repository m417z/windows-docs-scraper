## Description

The **ZwUnmapViewOfSection** routine unmaps a [view](https://learn.microsoft.com/windows-hardware/drivers/kernel/section-objects-and-views) of a section from the virtual address space of a subject process.

## Parameters

### `ProcessHandle` [in]

Handle to a process object that was previously passed to [ZwMapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmapviewofsection).

### `BaseAddress` [in, optional]

Pointer to the base virtual address of the view to unmap. This value can be any virtual address within the view.

## Return value

**ZwUnmapViewOfSection** returns an NTSTATUS value. Possible return values include:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The routine successfully performed the requested operation. |
| **STATUS_ACCESS_DENIED** | The caller does not have access rights to the process object or to the base virtual address of the view. |

## Remarks

This routine unmaps the entire view of the section that contains *BaseAddress* from the virtual address space of the specified process—even if *BaseAddress* does not point to the beginning of the view.

On return from **ZwUnmapViewOfSection**, the virtual-address region occupied by the view is no longer reserved and is available to map other views or private pages. If the view was also the last reference to the underlying section, all committed pages in the section are decommitted, and the section is deleted.

If the call to this function occurs in user mode, you should use the name "NtUnmapViewOfSection" instead of "**ZwUnmapViewOfSection**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwMapViewOfSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmapviewofsection)

[ZwOpenSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensection)