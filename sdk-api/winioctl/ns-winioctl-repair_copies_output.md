# REPAIR_COPIES_OUTPUT structure

## Description

Contains output of a repair copies operation returned from the
[FSCTL_REPAIR_COPIES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_repair_copies) control code.

## Members

### `Size`

Set to `sizeof(REPAIR_COPIES_OUTPUT)`.

### `Status`

Indicates the status of the repair operation. The value is a **NTSTATUS** value.
See
[http://msdn.microsoft.com/en-us/library/cc704588(PROT.10).aspx](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55)
for a list of **NTSTATUS** values.

### `ResumeFileOffset`

If the **Status** member indicates the operation was not successful, this is the
file offset to use to resume repair operations, skipping the range where errors were found.