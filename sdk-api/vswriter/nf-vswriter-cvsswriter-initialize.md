# CVssWriter::Initialize

## Description

Initializes a
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) object and allows a writer application to interact with VSS.

**Initialize** is a public method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Parameters

### `WriterId` [in]

The globally unique identifier (GUID) of the writer class.

### `wszWriterName` [in]

A **null**-terminated wide character string that contains the name of the writer. This string is not localized.

### `ut` [in]

A [VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type) enumeration value that indicates how the data managed by the writer is used on the host system.

### `st` [in]

A
[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type) enumeration value that indicates the type of data managed by the writer.

### `nLevel` [in]

A
[VSS_APPLICATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_application_level) enumeration value that indicates the application level at which the writer receives a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event notification.

The default value for this parameter is VSS_APP_FRONT_END.

### `dwTimeoutFreeze` [in]

The maximum permitted time, in milliseconds, between a writer's receipt of a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event notification and the receipt of a matching [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t) event notification from VSS. After the time-out expires, the writer's
[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort) method is called automatically.

The default value for this parameter is 60000.

### `aws` [in]

A [VSS_ALTERNATE_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_alternate_writer_state) enumeration value that indicates whether the writer has an associated alternate writer.

The default value for this parameter is VSS_AWS_NO_ALTERNATE_WRITER. The caller should not override this default value. This parameter is reserved for future use.

### `bIOThrottlingOnly` [in]

Set this parameter to **true** if I/O throttling methods are enabled, or **false** otherwise.

The default value for this parameter is **false**. The caller should not override this default value. This parameter is reserved for future use.

### `wszWriterInstanceName` [in]

A **null**-terminated wide character string that contains the writer instance name.

The default value for this parameter is **NULL**. If the writer has multiple instances and requires restore events, this parameter is required and cannot be **NULL**. For details, see the following Remarks section.

**Windows Server 2003 and Windows XP:** Before Windows Server 2003 with SP1, this parameter is reserved for system use, and the caller should not override the default value.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully initialized the writer object. |
| **S_FALSE** | The writer object could not be initialized; the VSS writer infrastructure was inactive because Windows was in safe mode or was setting up. |
| **E_ACCESSDENIED** | The caller is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

VSS assigns a unique writer instance ID to each instance of a writer application. If more than one instance is present on the system at the same time (for example, if multiple SQL servers are running on a system), each writer is uniquely identified by the combination of its writer class ID and its writer instance ID.

The *wszWriterInstanceName* parameter allows a multi-instance writer to specify a persistent name for each writer instance as a human-readable string. This name must be unique across all instances of the writer on the system. If a writer has multiple instances and requires restore events, it must specify a non-**NULL** string for this parameter. VSS uses the instance name to correctly restore multi-instance writers.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort)

[VSS_ALTERNATE_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_alternate_writer_state)

[VSS_APPLICATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_application_level)

[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)

[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type)

[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type)