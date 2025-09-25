# CVssWriter::Subscribe

## Description

The
**Subscribe** method subscribes the writer with VSS.

**Subscribe** is a public method implemented by the base class.

## Parameters

### `dwEventFlags` [in]

A bit mask (or bitwise OR) of
[VSS_SUBSCRIBE_MASK](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_subscribe_mask) values indicating the events that VSS should notify the writer about.

The default value for this argument is (VSS_SM_BACKUP_EVENTS_FLAG | VSS_SM_RESTORE_EVENTS_FLAG). Currently, the caller should not override the default value.

This parameter is reserved for future use.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully subscribed the writer object. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_WRITER_ALREADY_SUBSCRIBED** | The writer has previously called this method. |

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[CVssWriter::Unsubscribe](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-unsubscribe)

[VSS_SUBSCRIBE_MASK](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_subscribe_mask)