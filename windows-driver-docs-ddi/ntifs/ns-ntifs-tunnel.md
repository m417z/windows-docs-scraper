## Description

The **TUNNEL** structure is a tunnel cache structure.

## Members

### `Mutex`

A [**FAST_MUTEX**](https://learn.microsoft.com/windows-hardware/drivers/kernel/fast-mutexes-and-guarded-mutexes) structure that contains the mutex for cache manipulation.

### `Cache`

Pointer to a [**RTL_SPLAY_LINKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_rtl_splay_links) structure that contains the splay tree of tunneled information keyed by DirKey ## Name.

### `TimerQueue`

A [**LIST_ENTRY**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that contains the timer queue used to age entries out of the main cache.

### `NumEntries`

Number of entries in the cache. **NumEntries** is used to track the number of entries in the cache to prevent excessive use of memory.