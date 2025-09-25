# QUOTA_LIMITS structure

## Description

The **QUOTA_LIMITS** structure describes the amount of system resources available to a user.

## Members

### `PagedPoolLimit`

Specifies the amount of paged pool memory assigned to the user. The paged pool is an area of system memory (physical memory used by the operating system) for objects that can be written to disk when they are not being used.

The value set in this member is not enforced by the LSA. You should set this member to 0, which causes the default value to be used.

### `NonPagedPoolLimit`

Specifies the amount of nonpaged pool memory assigned to the user. The nonpaged pool is an area of system memory for objects that cannot be written to disk but must remain in physical memory as long as they are allocated.

The value set in this member is not enforced by the LSA. You should set this member to 0, which causes the default value to be used.

### `MinimumWorkingSetSize`

Specifies the minimum set size assigned to the user. The "working set" of a process is the set of memory pages currently visible to the process in physical RAM memory. These pages are present in memory when the application is running and available for an application to use without triggering a page fault.

The value set in this member is not enforced by the LSA. You should set this member to **NULL**, which causes the default value to be used.

### `MaximumWorkingSetSize`

Specifies the maximum set size assigned to the user.

The value set in this member is not enforced by the LSA. You should set this member to 0, which causes the default value to be used.

### `PagefileLimit`

Specifies the maximum size, in bytes, of the paging file, which is a reserved space on disk that backs up committed physical memory on the computer.

The value set in this member is not enforced by the LSA. You should set this member to 0, which causes the default value to be used.

### `TimeLimit`

Indicates the maximum amount of time the process can run.

The value set in this member is not enforced by the LSA. You should set this member to **NULL**, which causes the default value to be used.