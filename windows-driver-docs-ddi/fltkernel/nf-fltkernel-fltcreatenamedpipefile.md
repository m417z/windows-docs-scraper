# FltCreateNamedPipeFile function

## Description

Minifilter drivers call **FltCreateNamedPipeFile** to create a new pipe or open an existing pipe.

## Parameters

### `Filter` [in]

An opaque filter pointer for the caller.

### `Instance` [in, optional]

An opaque instance pointer for the minifilter driver instance that the create request is to be sent to. The instance must be attached to the volume for the named pipe file system. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the request is sent to the device object at the top of the file system driver stack for the volume. If it is non-**NULL**, the request is sent only to minifilter driver instances that are attached below the specified instance.

### `FileHandle` [out]

A pointer to a caller-allocated variable that receives the file handle if the call to **FltCreateNamedPipeFile** is successful.

### `FileObject` [out, optional]

A pointer to a caller-allocated variable that receives the file object pointer if the call to **FltCreateNamedPipeFile** is successful. This parameter is optional and can be **NULL**.

### `DesiredAccess` [in]

A bitmask of flags that specify the type of access that the caller requires to the file or directory. The set of system-defined *DesiredAccess* flags determines the following specific access rights for file objects.

| DesiredAccess Flags | Meaning |
| --- | --- |
| FILE_READ_DATA | Data can be read from the named pipe. |
| FILE_READ_ATTRIBUTES | *FileAttributes* flags can be read. For additional information, see the table of valid flag values in the *FileAttributes* parameter of [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2). |
| READ_CONTROL | The access control list ([ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) and ownership information associated with the named pipe can be read. |
| FILE_WRITE_DATA | Data can be written to the named pipe. |
| FILE_WRITE_ATTRIBUTES | *FileAttributes* flags can be written. |
| FILE_APPEND_DATA | Data can be appended to the file. |
| WRITE_DAC | The discretionary access control list ([DACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) associated with the named pipe can be written. |
| WRITE_OWNER | Ownership information associated with the named pipe can be written. |
| ACCESS_SYSTEM_SECURITY | The caller will have write access to the named pipe's SACL |
| SYNCHRONIZE | The caller can synchronize the completion of an I/O operation by waiting for the returned *FileHandle* to be set to the Signaled state. This flag must be set if the *CreateOptions* FILE_SYNCHRONOUS_IO_ALERT or FILE_SYNCHRONOUS_IO_NONALERT flag is set. |

Alternatively, for any file object that does not represent a directory, you can specify one or more of the following generic [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) flags. (The STANDARD_RIGHTS_*XXX* flags are predefined system values that are used to enforce security on system objects.) You can also combine these generic flags with additional flags from the preceding table.

| DesiredAccess to File Values | Maps to *DesiredAccess* Flags |
| --- | --- |
| GENERIC_READ | STANDARD_RIGHTS_READ, FILE_READ_DATA, and SYNCHRONIZE. |
| GENERIC_WRITE | STANDARD_RIGHTS_WRITE, FILE_WRITE_DATA, FILE_APPEND_DATA, and SYNCHRONIZE. |

### `ObjectAttributes` [in]

A pointer to an opaque [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that is already initialized with [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes). If the caller is running in the system process context, this parameter can be **NULL**. Otherwise, the caller must set the OBJ_KERNEL_HANDLE attribute in the call to **InitializeObjectAttributes**. Members of this structure for a file object are listed in the following table.

| Member | Value |
| --- | --- |
| **ULONG** **Length** | The number of bytes of data that are contained in the structure pointed to by *ObjectAttributes*. This value must be at least **sizeof**(OBJECT_ATTRIBUTES). |
| **PUNICODE_STRING** **ObjectName** | A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the pipe to be created or opened. This name must be a fully qualified file specification or the name of a device object unless it is the name of a file relative to the directory specified by **RootDirectory**. For example, "\Device\NamedPipe\mypipe" or "\??\pipe\mypipe" could both be valid file specifications. (Note: "\??" replaces "\DosDevices" as the name of the Win32 object namespace. "\DosDevices" still works, but "\??" is translated faster by the object manager.) |
| **HANDLE** **RootDirectory** | An optional handle to a directory, obtained by a preceding call to [FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2). If this value is **NULL**, the *ObjectName*member must be a fully qualified file specification that includes the full path to the target pipe. If this value is non-**NULL**, the *ObjectName* member specifies a pipe name that is relative to this directory. |
| **PSECURITY_DESCRIPTOR** **SecurityDescriptor** | An optional security descriptor ([SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)) to be applied to a pipe. [ACLs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl) specified by such a security descriptor are only applied to the pipe when it is created. If the value is **NULL** when a pipe is created, the ACL placed on the pipe is dependent on the named pipe file system and may allow a client with any access to create an instance. |
| **ULONG** **Attributes** | A set of flags that controls the file object attributes. If the caller is running in the system process context, this parameter can be zero. Otherwise, the caller must set the OBJ_KERNEL_HANDLE flag. The caller can also optionally set the OBJ_CASE_INSENSITIVE flag, which indicates that name-lookup code should ignore the case of *ObjectName* rather than performing an exact-match search. |

### `IoStatusBlock` [out]

A pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested operation. On return from **FltCreateNamedPipeFile**, the **Information** member of the variable contains one of the following values:

FILE_CREATED

FILE_OPENED

### `ShareAccess` [in]

The type of share access to the file that the caller requires as one or a combination of the following flags. For the greatest chance of avoiding sharing violation errors, specify all of the following share access flags.

| *ShareAccess* flags | Meaning |
| --- | --- |
| FILE_SHARE_READ | The file can be opened for read access by other threads' calls to **FltCreateNamedPipeFile**. |
| FILE_SHARE_WRITE | The file can be opened for write access by other threads' calls to **FltCreateNamedPipeFile**. |

### `CreateDisposition` [in]

A value that determines the action to be taken, depending on whether the file already exists. The value can be any of those described in the following table.

| *CreateDisposition* values | Meaning |
| --- | --- |
| FILE_CREATE | If the file already exists, fail the request and do not create or open the specified file. If it does not, create the file. |
| FILE_OPEN | If the file already exists, open it instead of creating a new file. If it does not, fail the request and do not create a new file. |
| FILE_OPEN_IF | If the file already exists, open it. If it does not, create the file. |

### `CreateOptions` [in]

The options to be applied when creating or opening the pipe, as a compatible combination of the following flags.

| *CreateOptions* flags | Meaning |
| --- | --- |
| FILE_WRITE_THROUGH | System services, pipe systems, and drivers that write data to the pipe must actually transfer the data into the pipe before any requested write operation is considered complete. This flag is automatically set if the *CreateOptions* flag FILE_NO_INTERMEDIATE_BUFFERING is set. |
| FILE_SYNCHRONOUS_IO_ALERT | All operations on the pipe are performed synchronously. Any wait on behalf of the caller is subject to premature termination from alerts. This flag also causes the I/O system to maintain the pipe position context. If this flag is set, the *DesiredAccess* SYNCHRONIZE flag also must be set so that the I/O Manager uses the file object as a synchronization object. |
| FILE_SYNCHRONOUS_IO_NONALERT | All operations on the pipe are performed synchronously. Waits in the system to synchronize I/O queuing and completion are not subject to alerts. This flag also causes the I/O system to maintain the file position context. If this flag is set, the *DesiredAccess* SYNCHRONIZE flag also must be set so that the I/O Manager uses the file object as a synchronization object. |

### `NamedPipeType` [in]

Type of named pipe to create. Can be one of the following values:

| Value | Meaning |
| --- | --- |
| **FILE_PIPE_BYTE_STREAM_TYPE** | The data is written to the pipe as a stream of bytes. To use this type, *ReadMode* must not be FILE_PIPE_MESSAGE_MODE. |
| **FILE_PIPE_MESSAGE_TYPE** | The data is written to the pipe as a message. |

### `ReadMode` [in]

The mode to read from the pipe.

| Value | Meaning |
| --- | --- |
| **FILE_PIPE_BYTE_STREAM_MODE** | The pipe data is read as a stream of bytes. |
| **FILE_PIPE_MESSAGE_MODE** | The pipe data is read as messages. To use this mode, *NamedPipeType* must be FILE_PIPE_MESSAGE_TYPE. |

### `CompletionMode` [in]

The completion mode for pipe reads and writes.

| Value | Meaning |
| --- | --- |
| **FILE_PIPE_QUEUE_OPERATION** | The pipe read and write requests are queued and can block until completed. |
| **FILE_PIPE_COMPLETE_OPERATION** | The pipe read and write requests are completed immediately. |

### `MaximumInstances` [in]

The maximum number of instances allowed for this named pipe.

### `InboundQuota`

The number of bytes to reserve for the input buffer.

### `OutboundQuota`

The number of bytes to reserve for the output buffer.

### `DefaultTimeout` [in, optional]

The default timeout in 100-nanosecond increments. This value is expressed as a negative integer. For example, 250 milliseconds is specified as –10 * 1000 * 250.

### `DriverContext` [in, optional]

An optional pointer to an [IO_DRIVER_CREATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context) structure already initialized by [IoInitializeDriverCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioinitializedrivercreatecontext).

## Return value

**FltCreateNamedPipeFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The filter or instance specified in the *Filter* or *Instance* parameters is being torn down. This status code can be received if the open request crosses a volume mount point and the *Instance* parameter is non-**NULL**. This is an error code. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The *ObjectAttributes* parameter did not contain a **RootDirectory** member, but the **ObjectName** member in the OBJECT_ATTRIBUTES structure was an empty string or did not contain an OBJECT_NAME_PATH_SEPARATOR character. This error code indicates incorrect syntax for the object path. |

## Remarks

The **FltCreateNamedPipeFile** function allows minifilter drivers to create or open pipe instances. This is useful for creating virtual pipes or for creating pipe unions for multiplexing I/O.

The *instance* parameter is either  **NULL** or is previously set by attaching to the named pipe volume. A volume pointer is obtained by passing "\Device\NamedPipe" as the volume name to [FltGetVolumeFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumefromname).

To specify an extra create parameter (ECP) as part of a create operation, initialize the **ExtraCreateParameter** member of the [IO_DRIVER_CREATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context) structure with the [FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist) routine. If ECPs are used, they must be allocated, initialized, and freed using their associated support routines. Upon returning from the call of **FltCreateNamedPipeFile**, the ECP list is unchanged and may be passed to additional calls of **FltCreateNamedPipeFile** for other create operations. The ECP list structure is not automatically deallocated. The caller of **FltCreateNamedPipeFile** must deallocate this structure by calling the [FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist) routine.

If *Instance* is not **NULL**, the create request from **FltCreateNamedPipeFile** is sent only to the instances attached below the specified minifilter driver instance and to the named pipe file system. The specified instance and the instances attached above it do not receive the create request. If no instance is specified, the request goes to the top of the stack and is received by all instances and the named pipe file system.

## See also

[FltAllocateExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameterlist)

[FltFreeExtraCreateParameterList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeextracreateparameterlist)

[IO_DRIVER_CREATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_driver_create_context)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[IoInitializeDriverCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioinitializedrivercreatecontext)