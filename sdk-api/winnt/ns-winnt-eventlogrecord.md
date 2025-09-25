# EVENTLOGRECORD structure

## Description

Contains information about an event record returned by the
[ReadEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readeventloga) function.

## Members

### `Length`

The size of this event record, in bytes. Note that this value is stored at both ends of the entry to ease moving forward or backward through the log. The length includes any pad bytes inserted at the end of the record for **DWORD** alignment.

### `Reserved`

A DWORD value that is always set to **ELF_LOG_SIGNATURE** (the value is 0x654c664c), which is ASCII for eLfL.

### `RecordNumber`

The number of the record. This value can be used with the EVENTLOG_SEEK_READ flag in the
[ReadEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readeventloga) function to begin reading at a specified record. For more information, see
[Event Log Records](https://learn.microsoft.com/windows/desktop/EventLog/event-log-records).

### `TimeGenerated`

The time at which this entry was submitted. This time is measured in the number of seconds elapsed since 00:00:00 January 1, 1970, Universal Coordinated Time.

### `TimeWritten`

The time at which this entry was received by the service to be written to the log. This time is measured in the number of seconds elapsed since 00:00:00 January 1, 1970, Universal Coordinated Time.

### `EventID`

The event identifier. The value is specific to the event source for the event, and is used with source name to locate a description string in the message file for the event source. For more information, see
[Event Identifiers](https://learn.microsoft.com/windows/desktop/EventLog/event-identifiers).

### `EventType`

The type of event. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **EVENTLOG_ERROR_TYPE**<br><br>0x0001 | Error event |
| **EVENTLOG_AUDIT_FAILURE**<br><br>0x0010 | Failure Audit event |
| **EVENTLOG_AUDIT_SUCCESS**<br><br>0x0008 | Success Audit event |
| **EVENTLOG_INFORMATION_TYPE**<br><br>0x0004 | Information event |
| **EVENTLOG_WARNING_TYPE**<br><br>0x0002 | Warning event |

For more information, see
[Event Types](https://learn.microsoft.com/windows/desktop/EventLog/event-types).

### `NumStrings`

The number of strings present in the log (at the position indicated by **StringOffset**). These strings are merged into the message before it is displayed to the user.

### `EventCategory`

The category for this event. The meaning of this value depends on the event source. For more information, see
[Event Categories](https://learn.microsoft.com/windows/desktop/EventLog/event-categories).

### `ReservedFlags`

Reserved.

### `ClosingRecordNumber`

Reserved.

### `StringOffset`

The offset of the description strings within this event log record.

### `UserSidLength`

The size of the **UserSid** member, in bytes. This value can be zero if no security identifier was provided.

### `UserSidOffset`

The offset of the security identifier (SID) within this event log record. To obtain the user name for this SID, use the
[LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida) function.

### `DataLength`

The size of the event-specific data (at the position indicated by **DataOffset**), in bytes.

### `DataOffset`

The offset of the event-specific information within this event log record, in bytes. This information could be something specific (a disk driver might log the number of retries, for example), followed by binary information specific to the event being logged and to the source that generated the entry.

## Remarks

The defined members are followed by the replacement strings for the message identified by the event identifier, the binary information, some pad bytes to make sure the full entry is on a **DWORD** boundary, and finally the length of the log entry again. Because the strings and the binary information can be of any length, no structure members are defined to reference them. The declaration of this structure in Winnt.h describes these members as follows:

``` syntax
    // WCHAR SourceName[]
    // WCHAR Computername[]
    // SID   UserSid
    // WCHAR Strings[]
    // BYTE  Data[]
    // CHAR  Pad[]
    // DWORD Length;
```

The source name is a variable-length string that specifies the name of the event source. The computer name is the name of the computer that generated the event. It may be followed with some padding bytes so that the user SID is aligned on a **DWORD** boundary. The user SID identifies the active user at the time this event was logged. If **UserSidLength** is zero, this field may be empty.

The event identifier together with source name and a language identifier identify a string that describes the event in more detail. The strings are used as replacement strings and are merged into the message string to make a complete message. The message strings are contained in a message file specified in the source entry in the registry. To obtain the appropriate message string from the message file, load the message file with the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function and use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function.

The binary information is information that is specific to the event. It could be the contents of the processor registers when a device driver got an error, a dump of an invalid packet that was received from the network, a dump of all the structures in a program (when the data area was detected to be corrupt), and so on. This information should be useful to the writer of the device driver or the application in tracking down bugs or unauthorized breaks into the application.

## See also

[LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida)

[ReadEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readeventloga)