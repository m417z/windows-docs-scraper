# PSAPI_WORKING_SET_EX_BLOCK structure

## Description

Contains extended working set information for a page.

## Members

### `Flags`

The working set information. See the description of the structure members for information about the layout
of this variable.

### `Valid`

If this bit is 1, the subsequent members are valid; otherwise they should be ignored.

### `ShareCount`

The number of processes that share this page. The maximum value of this member is 7.

### `Win32Protection`

The memory protection attributes of the page. For a list of values, see
[Memory Protection Constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants).

### `Shared`

If this bit is 1, the page can be shared.

### `Node`

The NUMA node. The maximum value of this member is 63.

### `Locked`

If this bit is 1, the virtual page is locked in physical memory.

### `LargePage`

If this bit is 1, the page is a large page.

### `Reserved`

Reserved.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available before Windows Server 2012 and Windows 8.

### `Bad`

If this bit is 1, the page is has been reported as bad.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available before Windows Server 2012 and Windows 8.

### `ReservedUlong`

Reserved. This member is only available on 64-bit code running on 64-bit editions of Windows.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available before Windows Server 2012 and Windows 8.

### `Invalid`

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This structure is not available before Windows Server 2012 and Windows 8.

### `Invalid.Valid`

If this bit is 0, the subsequent members are valid; otherwise they should be ignored.

### `Invalid.Reserved0`

Reserved.

### `Invalid.Shared`

If this bit is 1, the page can be shared.

### `Invalid.Reserved1`

Reserved.

### `Invalid.Bad`

If this bit is 1, the page is has been reported as bad.

### `Invalid.ReservedUlong`

Reserved. This member is only available on 64-bit code running on 64-bit editions of Windows.

## See also

[PSAPI Structures](https://learn.microsoft.com/windows/desktop/psapi/psapi-structures)

[PSAPI_WORKING_SET_EX_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_ex_information)

[QueryWorkingSetEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-queryworkingsetex)