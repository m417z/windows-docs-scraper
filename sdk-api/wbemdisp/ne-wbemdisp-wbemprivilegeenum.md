# WbemPrivilegeEnum enumeration

## Description

The
WbemPrivilegeEnum constants define privileges. These constants are used with
[SWbemSecurity](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity) to grant the privileges required for some operations. For more information, see
[Privilege Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/privilege-constants).

The WMI scripting type library, wbemdisp.tlb defines these constants. Microsoft Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemPrivilegeCreateToken:1`

Required to create a primary token.

### `wbemPrivilegePrimaryToken:2`

Required to assign the primary token of a process.

### `wbemPrivilegeLockMemory:3`

Required to lock physical pages in memory.

### `wbemPrivilegeIncreaseQuota:4`

Required to increase the quota assigned to a process.

### `wbemPrivilegeMachineAccount:5`

Required to create a machine account.

### `wbemPrivilegeTcb:6`

Identifies its holder as part of the trusted computer base. Some trusted, protected subsystems are granted this privilege.

### `wbemPrivilegeSecurity:7`

Required to perform a number of security-related functions, such as controlling and viewing audit messages. This privilege identifies its holder as a security operator.

### `wbemPrivilegeTakeOwnership:8`

Required to take ownership of an object without being granted discretionary access. This privilege allows the owner value to be set only to those values that the holder may legitimately assign as the owner of an object.

### `wbemPrivilegeLoadDriver:9`

Required to load or unload a device driver.

### `wbemPrivilegeSystemProfile:10`

Required to gather profiling information for the entire system.

### `wbemPrivilegeSystemtime:11`

Required to modify the system time.

### `wbemPrivilegeProfileSingleProcess:12`

Required to gather profiling information for a single process.

### `wbemPrivilegeIncreaseBasePriority:13`

Required to increase the base priority of a process.

### `wbemPrivilegeCreatePagefile:14`

Required to create a paging file.

### `wbemPrivilegeCreatePermanent:15`

Required to create a permanent object.

### `wbemPrivilegeBackup:16`

Required to perform backup operations.

### `wbemPrivilegeRestore:17`

Required to perform restore operations. This privilege enables you to set any valid user or group security identifier (SID) as the owner of an object.

### `wbemPrivilegeShutdown:18`

Required to shut down a local system.

### `wbemPrivilegeDebug:19`

Required to debug a process.

### `wbemPrivilegeAudit:20`

Required to generate audit-log entries.

### `wbemPrivilegeSystemEnvironment:21`

Required to modify the nonvolatile RAM of systems that use this type of memory to store configuration information.

### `wbemPrivilegeChangeNotify:22`

Required to receive notifications of changes to files or directories. This privilege also causes the system to skip all traversal access checks. It is enabled by default for all users.

### `wbemPrivilegeRemoteShutdown:23`

Required to shut down a system using a network request.

### `wbemPrivilegeUndock:24`

Required to remove a computer from a docking station.

### `wbemPrivilegeSyncAgent:25`

Required to synchronize directory service data.

### `wbemPrivilegeEnableDelegation:26`

Required to enable computer and user accounts to be trusted for delegation.

### `wbemPrivilegeManageVolume:27`

Required to perform volume maintenance tasks.

## See also

[Privilege Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/privilege-constants)

[SWbemSecurity.Privileges](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity-privileges)

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)