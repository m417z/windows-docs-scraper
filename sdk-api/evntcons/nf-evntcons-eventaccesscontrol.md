# EventAccessControl function (evntcons.h)

## Description

Adds or modifies the permissions of the specified provider or session.

## Parameters

### `Guid` [in]

GUID that uniquely identifies the provider or session whose permissions you want to add or modify.

### `Operation` [in]

Type of operation to perform, for example, add a DACL to the session's GUID or provider's GUID. For
possible values, see the [EVENTSECURITYOPERATION](https://learn.microsoft.com/windows/desktop/api/evntcons/ne-evntcons-eventsecurityoperation)
enumeration.

### `Sid` [in]

The security identifier (SID) of the user or group to whom you want to grant or deny permissions.

### `Rights` [in]

You can specify one or more of the following permissions:

| Value | Meaning |
| --- | --- |
| **WMIGUID_QUERY** | Allows the user to query information about the trace session. Set this permission on the session's GUID. |
| **TRACELOG_CREATE_REALTIME** | Allows the user to start or update a real-time session. Set this permission on the session's GUID. |
| **TRACELOG_CREATE_ONDISK** | Allows the user to start or update a session that writes events to a log file. Set this permission on the session's GUID. |
| **TRACELOG_GUID_ENABLE** | Allows the user to enable the provider. Set this permission on the provider's GUID. |
| **TRACELOG_ACCESS_KERNEL_LOGGER** | Not used. |
| **TRACELOG_LOG_EVENT** | Allows the user to log events to a trace session if session is running in SECURE mode (the session set the EVENT_TRACE_SECURE_MODE flag in the LogFileMode member of EVENT_TRACE_PROPERTIES). |
| **TRACELOG_ACCESS_REALTIME** | Allows a user to consume events in real-time. Set this permission on the session's GUID. |
| **TRACELOG_REGISTER_GUIDS** | Allows the user to register the provider. Set this permission on the provider's GUID. |

### `AllowOrDeny` [in]

If **TRUE**, grant the user permissions to the session or provider; otherwise, deny
permissions. This value is ignored if the value of *Operation* is EventSecuritySetSACL
or EventSecurityAddSACL.

## Return value

Returns ERROR_SUCCESS if successful.

## Remarks

By default, only the administrator of the computer, users in the Performance Log Users group, and services
running as LocalSystem, LocalService, NetworkService can control trace sessions and provide and consume event
data. Only users with administrative privileges and services running as LocalSystem can start and control an
NT Kernel Logger session.

**Windows Server 2003:** Only users with administrator privileges can control trace sessions and consume event data; any user can provide event data.

**Windows XP and Windows 2000:** Any user can control trace sessions and provide and consume event data.

Users with administrator privileges can control trace sessions if the tool that they use to control the session
is started from a Command Prompt window that is opened with
**Run as administrator...**.

To grant a restricted user the ability to control trace sessions, you can add them to the Performance Log Users
group or call this function to grant them permission. For example, you can grant user A permission to start and
stop a trace session and grant user B permission to only query the session.

To restrict who can log events to the session, see the TRACELOG_LOG_EVENT permission.

The ACL on the log file determines who can consume event data from the log file. To consume events from a
session in real-time, you must grant the user TRACELOG_ACCESS_REALTIME permission or the user must be a member of
the Performance Log Users group.

You can also specify the provider's GUID to restrict who can register the provider and who can enable the
provider.

## See also

[EventAccessQuery](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccessquery)

[EventAccessRemove](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccessremove)