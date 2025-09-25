# FsRtlSupportsPerFileContexts macro

## Description

The **FsRtlSupportsPerFileContexts** macro checks if per file context information is supported by the file system that is associated with a specified [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object).

## Parameters

### `_fo`

A FILE_OBJECT that is associated with the file system to be checked.

## Remarks

None

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)