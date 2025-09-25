# CVssWriterEx::InitializeEx

## Description

Initializes a
[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex) object and allows a writer application to interact with VSS. Unlike the [Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize) method, the **InitializeEx** method allows the caller to specify writer version information.

**InitializeEx** is a public method implemented by the
[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex) base class.

Writers must call [Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize) or **InitializeEx**, but not both.

## Parameters

### `WriterId` [in]

The globally unique identifier (GUID) of the writer class.

### `wszWriterName` [in]

A **null**-terminated wide character string that contains the name of the writer. This string is not localized.

### `dwMajorVersion` [in]

The major version of the writer application. For more information, see the Remarks section.

### `dwMinorVersion` [in]

The minor version of the writer application. For more information, see the Remarks section.

### `ut` [in]

A [VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type) enumeration value that indicates how the data that is managed by the writer is used on the host system.

### `st` [in]

A
[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type) enumeration value that indicates the type of data that is managed by the writer.

### `nLevel` [in]

A
[VSS_APPLICATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_application_level) enumeration value that indicates the application level at which the writer receives a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event notification.

The default value for this parameter is VSS_APP_FRONT_END.

### `dwTimeoutFreeze` [in]

The maximum permitted time, in milliseconds, between the writer's receipt of a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event notification and its receipt of a matching [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t) event notification from VSS. After the time-out expires, the writer's
[OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort) method is called automatically.

The default value for this parameter is 60000.

### `aws` [in]

A [VSS_ALTERNATE_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_alternate_writer_state) enumeration value that indicates whether the writer has an associated alternate writer.

The default value for this parameter is VSS_AWS_NO_ALTERNATE_WRITER. The caller should not override this default value. This parameter is reserved for future use.

### `bIOThrottlingOnly` [in]

Set this parameter to **true** if I/O throttling methods are enabled, or **false** otherwise.

The default value for this parameter is **false**. The caller should not override this default value. This parameter is reserved for future use.

### `wszWriterInstanceName` [in]

A **null**-terminated wide character string that contains the writer instance name.

The default value for this parameter is **NULL**. If the writer has multiple instances and requires restore events, this parameter is required and cannot be **NULL**. For more information, see the following Remarks section.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer object was successfully initialized. |
| **S_FALSE** | The writer object could not be initialized; the VSS writer infrastructure was inactive because Windows was in safe mode or was setting up. |
| **E_ACCESSDENIED** | The caller is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The **InitializeEx** method is identical to the [Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize) method except for the *dwMajorVersion* and *dwMinorVersion* parameters. If the writer uses **Initialize** instead of **InitializeEx**, the writer version will be reported as 0.0 (major version = 0, minor version = 0) by the [IVssExamineWriterMetadataEx2::GetVersion](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getversion) method.

The *dwMajorVersion* and *dwMinorVersion* parameters are used to specify the writer major and minor version numbers according to the following VSS conventions:

* If the writer has changed since Windows XP or is new for Windows Vista, it should specify 1.0 or higher for its version number.
* A writer's minor version number should be incremented by one whenever a released version of the writer contains minor changes that affect the writer's interaction with requesters. For example, a correction to a file specification in a writer QFE or service pack would justify incrementing the minor version number. However, a change between beta or release candidate versions of a writer would not justify the changing of the minor version number.
* A writer's major version number should be incremented by one whenever a released version of the writer contains a significant change. For example, if data that is backed up with a new version of a writer cannot be restored using the previous version of the writer, the new writer's major version number should be incremented.
* Whenever the major version number is incremented, the minor version number should be reset to zero.

If a writer does not specify a version number, VSS will assign a default version number of 0.0.

VSS assigns a unique writer instance ID to each instance of a writer application. If more than one instance is present on the system at the same time (for example, if multiple SQL servers are running on a system), each writer is uniquely identified by the combination of its writer class ID and its writer instance ID.

The *wszWriterInstanceName* parameter allows a multi-instance writer to specify a persistent name for each writer instance as a human-readable string. This name must be unique across all instances of the writer on the system. If a writer has multiple instances and requires restore events, it must specify a non-**NULL** string for this parameter. VSS uses the instance name to correctly restore multi-instance writers.

## See also

[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex)

[IVssExamineWriterMetadataEx2::GetVersion](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex2-getversion)