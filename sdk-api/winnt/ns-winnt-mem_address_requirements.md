# MEM_ADDRESS_REQUIREMENTS structure

## Description

Specifies a lowest and highest base address and alignment as part of an extended parameter to a function that manages virtual memory.

## Members

### `LowestStartingAddress`

Specifies the lowest acceptable address.
This address must be a multiple of the allocation granularity returned by [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo),
or a multiple of the large page size returned by [GetLargePageMinimum](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-getlargepageminimum) if large pages are being requested.
If this member is **NULL**, then there is no lower limit.

### `HighestEndingAddress`

Specifies the highest acceptable address (inclusive).
This address must not exceed **lpMaximumApplicationAddress** returned by [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo).
If this member is **NULL**, then there is no upper limit.

### `Alignment`

Specifies power-of-2 alignment. Specifying 0 aligns the returned address on the system allocation granularity.

## Remarks

Specifying a **MEM_ADDRESS_REQUIREMENTS** structure with all fields set to 0 is the same as not specifying one at all.