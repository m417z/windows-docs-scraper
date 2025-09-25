# PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY structure

## Description

Used to impose restrictions on what system calls can be invoked by a process.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

This member is reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisallowWin32kSystemCalls`

When set to 1, the process is not permitted to perform GUI system calls.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditDisallowWin32kSystemCalls`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DisallowFsctlSystemCalls`

When set to 1, the process is not be able to successfully make NtFsControlFile system calls, with the following FsControlCode exceptions.

- FSCTL_IS_VOLUME_MOUNTED
- FSCTL_PIPE_IMPERSONATE
- FSCTL_PIPE_LISTEN
- FSCTL_PIPE_DISCONNECT
- FSCTL_PIPE_TRANSCEIVE
- FSCTL_PIPE_WAIT
- FSCTL_PIPE_GET_PIPE_ATTRIBUTE
- FSCTL_PIPE_GET_CONNECTION_ATTRIBUTE
- FSCTL_PIPE_GET_HANDLE_ATTRIBUTE
- FSCTL_PIPE_PEEK
- FSCTL_PIPE_EVENT_SELECT
- FSCTL_PIPE_EVENT_ENUM

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditDisallowFsctlSystemCalls`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

This member is reserved for system use.