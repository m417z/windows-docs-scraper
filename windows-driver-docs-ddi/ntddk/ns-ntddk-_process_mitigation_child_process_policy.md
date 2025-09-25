# _PROCESS_MITIGATION_CHILD_PROCESS_POLICY structure

## Description

Stores policy information about creating child processes.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.NoChildProcessCreation`

If set, the process cannot create child processes.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditNoChildProcessCreation`

If set, causes audit events to be generated when child processes are created by the process. If both **NoChildProcessCreation** and **AuditNoChildProcessCreation** are set, **NoChildProcessCreation** takes precedence over audit setting.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AllowSecureProcessCreation`

Denies creation of child processes unless the child process is a secure process and if creation was previously blocked. It allows a process to spawn a child process on behalf of another process that cannot itself create child processes. See PROCESS_CREATION_CHILD_PROCESS_OVERRIDE in [UpdateProcThreadAttribute](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved.