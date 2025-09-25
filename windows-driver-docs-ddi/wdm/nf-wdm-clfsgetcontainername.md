# ClfsGetContainerName function

## Description

The **ClfsGetContainerName** routine returns the path name of a specified container.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS log. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `cidLogicalContainer` [in]

The logical identifier of a container in the CLFS log.

### `puszContainerName` [out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. The **Buffer** member of *puszContainerName* must point to a caller-allocated buffer that receives the path name of the container. The **MaximumLength** member must supply the size of the buffer.

### `pcActualLenContainerName` [out, optional]

A pointer to a ULONG-typed variable that receives the actual length, in Unicode characters, of the container's path name. This parameter can be **NULL**.

## Return value

**ClfsGetContainerName** returns one of the status codes defined in Ntstatus.h. The following table gives the meanings of various return values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The **Buffer** member of *puszContainerName* receives the full path name of the container. If *pcActualLenContainerName* is not **NULL**, it receives the actual length, in Unicode characters, of the full path name. |
| **STATUS_BUFFER_OVERFLOW** | The actual length, in Unicode characters, of the full path name is larger than *puszContainerName*->**MaximumLength**. The **Buffer** member of *puszContainerName* receives the full path name of the container truncated to the number of characters specified by *puszContainerName*->**MaximumLength**. If *pcActualLenContainerName* is not **NULL**, it receives the actual length, in Unicode characters, of the full path name. |
| **Other** | On return, the contents of *puszContainerName*->**Buffer** and *pcActualLenContainerName* are undefined. |

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsAddLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsaddlogcontainer)

[ClfsRemoveLogContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsremovelogcontainer)