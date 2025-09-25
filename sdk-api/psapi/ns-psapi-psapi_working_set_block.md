# PSAPI_WORKING_SET_BLOCK structure

## Description

Contains working set information for a page.

## Members

### `Flags`

The working set information. See the description of the structure members for information about the layout of this variable.

### `Protection`

The protection attributes of the page. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The page is not accessed. |
| 1 | Read-only. |
| 2 | Executable. |
| 3 | Executable and read-only. |
| 4 | Read/write. |
| 5 | Copy-on-write. |
| 6 | Executable and read/write. |
| 7 | Executable and copy-on-write. |
| 8 | The page is not accessed. |
| 9 | Non-cacheable and read-only. |
| 10 | Non-cacheable and executable. |
| 11 | Non-cacheable, executable, and read-only. |
| 12 | Non-cacheable and read/write. |
| 13 | Non-cacheable and copy-on-write. |
| 14 | Non-cacheable, executable, and read/write. |
| 15 | Non-cacheable, executable, and copy-on-write. |
| 16 | The page is not accessed. |
| 17 | Guard page and read-only. |
| 18 | Guard page and executable. |
| 19 | Guard page, executable, and read-only. |
| 20 | Guard page and read/write. |
| 21 | Guard page and copy-on-write. |
| 22 | Guard page, executable, and read/write. |
| 23 | Guard page, executable, and copy-on-write. |
| 24 | The page is not accessed. |
| 25 | Non-cacheable, guard page, and read-only. |
| 26 | Non-cacheable, guard page, and executable. |
| 27 | Non-cacheable, guard page, executable, and read-only. |
| 28 | Non-cacheable, guard page, and read/write. |
| 29 | Non-cacheable, guard page, and copy-on-write. |
| 30 | Non-cacheable, guard page, executable, and read/write. |
| 31 | Non-cacheable, guard page, executable, and copy-on-write. |

### `ShareCount`

The number of processes that share this page. The maximum value of this member is 7.

### `Shared`

If this bit is 1, the page is sharable; otherwise, the page is not sharable.

### `Reserved`

This member is reserved.

### `VirtualPage`

The address of the page in the virtual address space.

**64-bit Windows:** This member is 52 bits in length.

## See also

[PSAPI_WORKING_SET_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_working_set_information)