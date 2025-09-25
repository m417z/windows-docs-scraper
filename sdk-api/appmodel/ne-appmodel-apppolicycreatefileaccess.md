# AppPolicyCreateFileAccess enumeration

## Description

The AppPolicyCreateFileAccess enumeration indicates whether a process has full or restricted access to the IO devices (file, file stream, directory, physical disk, volume, console buffer, tape drive, communications resource, mailslot, and pipe).

## Constants

### `AppPolicyCreateFileAccess_Full`

Indicates that the process has full access to the IO devices. This value is expected for a desktop application, or for a Desktop Bridge application.

### `AppPolicyCreateFileAccess_Limited`

Indicates that the process has limited access to the IO devices. This value is expected for a UWP app.