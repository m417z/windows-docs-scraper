# ClfsCreateLogFile function

## Description

The **ClfsCreateLogFile** routine creates or opens a CLFS stream. If necessary, **ClfsCreateLogFile** also creates the underlying physical log that holds the stream's records.

## Parameters

### `pplfoLog` [out]

A pointer to a variable that receives a pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents an open instance of the stream.

### `puszLogFileName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that supplies the name of the stream or the underlying physical log.

If the stream already exists and is the only stream of a dedicated log, the name has the form log:*physical log name*, where *physical log name* is the path name, on the underlying file system, of the existing physical log that contains the stream's records.

If the stream does not already exist and is to become the only stream of a dedicated log (that does not yet exist), the name has the form log:*physical log name*, where *physical log name* is the path name, on the underlying file system, of the physical log that will be created to hold the stream's records.

If the stream is (or is to become) one of the streams of a multiplexed log, the name has the form log:*physical log name*::*stream name*, where *physical log name* is the path name, on the underlying file system, of the physical log that holds the stream's records, and *stream name* is the name of a stream that shares (or will share) that physical log.

If you want to create a multiplexed log that has no streams for the moment, use a name of the form log:*physical log name*::, where *physical log name* is the path name, on the underlying file system, of the physical log to be created.

The following list gives some examples of valid names.

* "Log:c:\myLog" creates or opens a dedicated log and its one stream.
* "Log:c:\myCommonLog::" creates a multiplexed log that does not yet have any streams.
* "Log:c:\myCommonLog::Stream1" creates or opens one of the streams (Stream1) of a multiplexed log.

### `fDesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) that supplies the type of access the client will have (by using the pointer returned in *pplfoLog*) to the stream. If this parameter is zero, clients can query the stream for its attributes, but cannot read from or write to the stream. This parameter can be zero or any combination of the following flags:

| Flag | Meaning |
| --- | --- |
| GENERIC_READ | The client has read access to the stream. |
| GENERIC_WRITE | The client has write access to the stream. |
| DELETE | The client can mark the stream for deletion. |

### `dwShareMode` [in]

The sharing mode of the stream, which can be zero (not shared) or any combination of the following flags:

| Flag | Meaning |
| --- | --- |
| FILE_SHARE_DELETE | Subsequent requests to open the stream with delete access will succeed. |
| FILE_SHARE_READ | Subsequent requests to open the stream with read access will succeed. |
| FILE_SHARE_WRITE | Subsequent requests to open the stream with write access will succeed. |

### `psdLogFile` [in, optional]

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that supplies security attributes for the stream. This parameter can be **NULL**.

### `fCreateDisposition` [in]

The action to take that depends on whether the stream already exists. This parameter must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| CREATE_NEW | Create a new stream if the stream does not already exits. Fail if the stream already exists. |
| OPEN_EXISTING | Open an existing stream. Fail if the stream does not already exist. |
| OPEN_ALWAYS | Open an existing stream. Create the stream if it does not already exist. |

### `fCreateOptions` [in]

A set of flags that specify options to apply when creating or opening the stream. This parameter can be zero or a compatible combination of the following flags:

| Flag | Meaning |
| --- | --- |
| FILE_NO_INTERMEDIATE_BUFFERING | The stream's records cannot be cached in a driver's internal buffers. |
| FILE_SYNCHRONOUS_IO_ALERT | All operations on the stream are performed synchronously. Any wait on behalf of the caller is subject to premature termination from alerts. If this flag is set, the FILE_SYNCHRONOUS_IO_NONALERT flag must be cleared. |
| FILE_SYNCHRONOUS_IO_NONALERT | All operations on the stream are performed synchronously. Waits in the system that synchronize I/O queuing and completion are not subject to alerts. If this flag is set, the FILE_SYNCHRONOUS_IO_ALERT flag must be cleared. |

### `fFlagsAndAttributes` [in]

A value that specifies whether the stream is opened for normal or read-only access. This parameter must be set to either

FILE_ATTRIBUTE_NORMAL or FILE_ATTRIBUTE_READONLY.

### `fLogOptionFlag` [in]

A hint about the relationship between CLFS and the component creating or opening the stream. This parameter must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| CLFS_FLAG_NO_FLAGS | CLFS and the creating component have the standard, normal relationship. Kernel-mode components use this value unless they fall into one of the three other categories listed in this table. If *pvContext* is not **NULL**, CLFS verifies that *cbContext* is greater than zero. Otherwise, *pvContext* and *cbContext* are ignored. |
| CLFS_FLAG_REENTRANT_FILE_SYSTEM | The creating component is the file system that provides the underlying storage for CLFS. CLFS uses the file system for allocating containers, and the file system uses CLFS streams. In this case, it is possible for the file system to call CLFS and for CLFS to make calls back into the file system on the same thread or different threads. If *pvContext* is not **NULL**, CLFS verifies that *cbContext* is greater than zero. Otherwise, *pvContext* and *cbContext* are ignored. |
| CLFS_FLAG_NON_REENTRANT_FILTER | The creating component is a file system filter driver that sends all of its CLFS I/O to a specified level below itself on the filter stack. This option allows a filter driver to create a CLFS log without seeing its own logging I/O. The caller passes the non-**NULL** target device object in the *pvContext* parameter with *cbContext* set to the appropriate size. CLFS uses the [IoCreateFileSpecifyDeviceObjectHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefilespecifydeviceobjecthint) routine to create containers at a targeted level in the I/O filter stack specified by the device object. |
| CLFS_FLAG_REENTRANT_FILTER | The creating component is a file system filter driver that sends all of its CLFS I/O to the top of the filter stack. The filter has a recursive relationship with CLFS because it filters its own logging I/O when CLFS performs any file system operation on its containers. The *pvContext* parameter provides a means for filters to associate a recognizable context with its CLFS containers as log I/O comes down the filter stack. The *cbContext* parameter specifies the size of the opaque context in bytes. |
| CLFS_FLAG_MINIFILTER_LEVEL | The creating component is a file system minifilter driver that sends all of its CLFS I/O to a specified level below itself on the filter stack. This option allows a minifilter to create a CLFS log without seeing its own logging I/O. The caller passes the non-**NULL** minifilter context object in the *pvContext* parameter with *cbContext* set to the appropriate size. CLFS uses the **IoCreateFileSpecifyDeviceObjectHint** routine to create containers at an altitude (specified within the minifilter context) in the filter manager's minifilter stack. |

### `pvContext` [in, optional]

A pointer to a context. The way the context is interpreted depends on the value passed to *fLogOptionsFlag*.

### `cbContext` [in]

The size, in bytes, of the context pointed to by *pvContext*. If *pvContext* is not **NULL**, this parameter must be greater than zero.

## Return value

**ClfsCreateLogFile** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

When you create a CLFS stream, it is backed by an underlying physical CLFS log. The underlying log can be either dedicated (backs only one stream) or multiplexed (backs several streams). A dedicated log cannot be converted to a multiplexed log, and a multiplexed log cannot be converted to a dedicated log.

A physical CLFS log name does not include the .blf extension.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsCloseAndResetLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloseandresetlogfile)

[ClfsCloseLogFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscloselogfileobject)

[ClfsDeleteLogByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogbypointer)

[ClfsDeleteLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsdeletelogfile)