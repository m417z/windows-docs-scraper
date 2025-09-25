## Description

The **ZwAllocateLocallyUniqueId** routine allocates a locally unique identifier ([**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)).

## Parameters

### `Luid`

Pointer to a caller-allocated buffer to receive a copy of the source LUID structure. The buffer must be at least **sizeof**(*LUID*).

## Return value

**ZwAllocateLocallyUniqueId** returns STATUS_SUCCESS if the operation succeeds or the appropriate NTSTATUS value if the operation fails. If the output parameter cannot be written to, the routine returns STATUS_ACCESS_VIOLATION.

## Remarks

The allocated [LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid) is unique to the local system only, and uniqueness is guaranteed only until the system is next restarted.

If the call to the **ZwAllocateLocallyUniqueId** function occurs in user mode, you should use the name "**NtAllocateLocallyUniqueId**" instead of "**ZwAllocateLocallyUniqueId**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)