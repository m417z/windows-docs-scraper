# SE_EXPORTS structure

## Description

The **SeExports** structure is a large external static SE_EXPORTS structure that defines a number of well-known security constants for privilege values and security identifiers.

## Members

### `SeCreateTokenPrivilege`

The privilege that is required to create a primary access token.

User-mode applications represent this privilege as the following user-right string: "Create a token object".

### `SeAssignPrimaryTokenPrivilege`

The privilege that is required to assign the primary token of a process. The privilege allows a parent process to replace the access token that is associated with a child process.

User-mode applications represent this privilege as the following user-right string: "Replace a process-level token".

### `SeLockMemoryPrivilege`

The privilege that is required to lock physical pages in memory. This privilege allows a process to keep data in physical memory, which prevents the system from paging the data to virtual memory on a disk.

User-mode applications represent this privilege as the following user-right string: "Required to lock physical pages in memory".

### `SeIncreaseQuotaPrivilege`

The privilege that is required to increase the quota assigned to a process. The privilege allows a process that has access to a second process to increase the processor quota assigned to the second process. This privilege is useful for system tuning, but it can be abused.

User-mode applications represent this privilege as the following user-right string: "Adjust memory quotas for a process".

### `SeUnsolicitedInputPrivilege`

The privilege that is required to read unsolicited input from a terminal device. This privilege is obsolete and unused. It has no effect on the system.

### `SeTcbPrivilege`

The privilege that identifies its holder as part of the trusted computer base. Typically, only low-level authentication services require this privilege. Some trusted protected subsystems are granted this privilege.

User-mode applications represent this privilege as the following user-right string: "Act as part of the operating system".

### `SeSecurityPrivilege`

The privilege that is required to perform a number of security-related functions, such as controlling and viewing audit messages. This privilege identifies its holder as a security operator. This privilege allows a user to specify object access auditing options for individual resources, including files, Active Directory objects, and Registry keys. A user who has this privilege can also view and clear the security log from Event Viewer.

User-mode applications represent this privilege as the following user-right string: "Manage auditing and security log".

### `SeTakeOwnershipPrivilege`

The privilege that is required to take ownership of an object without being granted discretionary access. This privilege allows the user to take ownership of any securable object in the system, including Active Directory objects, files and folders, printers, registry keys, processes, and threads. This privilege allows the owner value to be set only to those values that the holder might legitimately assign as the owner of an object.

User-mode applications represent this privilege as the following user-right string: "Take ownership of files or other objects".

### `SeLoadDriverPrivilege`

The privilege that is required to load or unload a device driver. This privilege allows a user to install and remove drivers for Plug and Play devices. This privilege is not required if a signed driver for the new hardware already exists in the *Driver.cab* file on the computer.

User-mode applications represent this privilege as the following user-right string: "Load and unload device drivers".

### `SeCreatePagefilePrivilege`

The privilege that is required to create and change the size of a paging file.

User-mode applications represent this privilege as the following user-right string: "Create a pagefile".

### `SeIncreaseBasePriorityPrivilege`

The privilege that is required to increase the base priority of a process. This privilege allows a user to increase the base priority class of a process. Increasing relative priority within a priority class is not a privileged operation and does not need this privilege.

User-mode applications represent this privilege as the following user-right string: "Increase scheduling priority".

### `SeSystemProfilePrivilege`

The privilege that is required to gather profiling information for the entire system. The privilege allows a user to sample the performance of system processes.

User-mode applications represent this privilege as the following user-right string: "Profile system performance".

### `SeSystemtimePrivilege`

The privilege that is required to modify the system time. This privilege allows the user to adjust the time on the computer's internal clock. This privilege is not required to change the time zone or other display characteristics of the system time.

User-mode applications represent this privilege as the following user-right string: "Change the system time".

### `SeProfileSingleProcessPrivilege`

The privilege that is required to gather profiling information for a single process. The privilege allows a user to sample the performance of an application process.

User-mode applications represent this privilege as the following user-right string: "Profile single process".

### `SeCreatePermanentPrivilege`

The privilege that is required to create a permanent object. This privilege allows a process to create a directory object in the object manager. This privilege is useful to kernel-mode components that extend the object namespace. Components that are running in kernel mode have this privilege inherently.

User-mode applications represent this privilege as the following user-right string: "Create permanent shared objects".

### `SeBackupPrivilege`

The privilege that is required to perform backup operations. This privilege allows the user to circumvent file and directory permissions to back up the system. This privilege causes the system to grant all read access control to any file, regardless of the access control list (ACL) specified for the file. Any access request other than read is still evaluated with the ACL. This privilege is required by the user-mode [**RegSaveKey**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeya) and [**RegSaveKeyEx**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeyexa) routines. The following access rights are granted if this privilege is held:

* READ_CONTROL
* ACCESS_SYSTEM_SECURITY
* FILE_GENERIC_READ
* FILE_TRAVERSE

User-mode applications represent this privilege as the following user-right string: "Back up files and directories".

### `SeRestorePrivilege`

The privilege that is required to perform restore operations. This privilege allows a user to circumvent file and directory permissions when restoring backed-up files and directories and to set any valid security principal as the owner of an object. This privilege causes the system to grant all write access control to any file, regardless of the ACL specified for the file. Any access request other than write is still evaluated with the ACL. Additionally, this privilege enables you to set any valid user or group SID as the owner of a file. This privilege is required by the user-mode [**RegLoadKey**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regloadkeya) and [**RegUnLoadKey**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regunloadkeya) routines that add or remove a hive from the registry. The following access rights are granted if this privilege is held:

* WRITE_DAC
* WRITE_OWNER
* ACCESS_SYSTEM_SECURITY
* FILE_GENERIC_WRITE
* FILE_ADD_FILE
* FILE_ADD_SUBDIRECTORY
* DELETE

User-mode applications represent this privilege as the following user-right string: "Restore files and directories".

### `SeShutdownPrivilege`

The privilege that is required to shut down a local system.

User-mode applications represent this privilege as the following user-right string: "Shut down the system".

### `SeDebugPrivilege`

The privilege that is required to debug and adjust the memory of a process owned by another account. This privilege allows the user to attach a debugger to any process. This privilege provides access to sensitive and critical operating system components.

User-mode applications represent this privilege as the following user-right string: "Debug programs".

### `SeAuditPrivilege`

The privilege that is required to generate audit-log entries in the security log. The security log can be used to trace unauthorized system access. This privilege should be given to secure servers.

User-mode applications represent this privilege as the following user-right string: "Generate security audits".

### `SeSystemEnvironmentPrivilege`

The privilege required to modify the nonvolatile RAM of systems that use this type of memory to store configuration information.

User-mode applications represent this privilege as the following user-right string: "Modify firmware environment values".

### `SeChangeNotifyPrivilege`

The privilege that is required to receive notifications of changes to files or directories. This privilege allows the user to pass through folders to which the user otherwise has no access while navigating an object path in the NTFS file system or in the registry. This privilege does not allow the user to list the contents of a folder; it allows the user only to traverse its directories. This privilege causes the system to skip all traversal access checks. It is enabled by default for all users.

User-mode applications represent this privilege as the following user-right string: "Bypass traverse checking".

### `SeRemoteShutdownPrivilege`

The privilege that is required to shut down a system by using a network request. This privilege allows a user to shut down a computer from a remote location on the network.

User-mode applications represent this privilege as the following user-right string: "Force shutdown from a remote system".

### `SeNullSid`

The null SID.

### `SeWorldSid`

The SID that matches everyone.

### `SeLocalSid`

The local SID.

### `SeCreatorOwnerSid`

The SID that matches the owner or creator of an object. This SID is used in inheritable access control entries (ACEs).

### `SeCreatorGroupSid`

The SID that matches the creator group of an object. This SID is used in inheritable ACEs.

### `SeNtAuthoritySid`

The SID for the Microsoft Windows NT authority.

### `SeDialupSid`

The SID for a dial-up account.

### `SeNetworkSid`

The SID for a network account. This SID is added to the process of a token when it logs on across a network. The corresponding logon type is LOGON32_LOGON_NETWORK.

### `SeBatchSid`

The SID for a batch process. This SID is added to the process of a token when it logs on as a batch job. The corresponding logon type is LOGON32_LOGON_BATCH.

### `SeInteractiveSid`

The SID for an interactive account. This SID is added to the process of a token when it logs on interactively. The corresponding logon type is LOGON32_LOGON_INTERACTIVE.

### `SeLocalSystemSid`

The SID that matches the LocalSystem account, a predefined local account used by the Service Control Manager. This account is not recognized by the security subsystem. It has extensive privileges on the local computer and acts as the computer on the network. Its token includes the Windows NT AUTHORITY\SYSTEM and BUILTIN\Administrators SIDs; these accounts have access to most system objects. The name of the account in all locales is ".\LocalSystem". The name, "LocalSystem" or "ComputerName\LocalSystem" can also be used. This account does not have a password.

A service that runs in the context of the LocalSystem account inherits the security context of the Service Control Manager. The account is not associated with any logged-on user account.

The LocalSystem account has the following privileges:

* SE_ASSIGNPRIMARYTOKEN_NAME
* SE_AUDIT_NAME
* SE_BACKUP_NAME
* SE_CHANGE_NOTIFY_NAME
* SE_CREATE_PAGEFILE_NAME
* SE_CREATE_PERMANENT_NAME
* SE_CREATE_TOKEN_NAME
* SE_DEBUG_NAME
* SE_INC_BASE_PRIORITY_NAME
* SE_INCREASE_QUOTA_NAME
* SE_LOAD_DRIVER_NAME
* SE_LOCK_MEMORY_NAME
* SE_PROF_SINGLE_PROCESS_NAME
* SE_RESTORE_NAME
* SE_SECURITY_NAME
* SE_SHUTDOWN_NAME
* SE_SYSTEM_ENVIRONMENT_NAME
* SE_SYSTEM_PROFILE_NAME
* SE_SYSTEMTIME_NAME
* SE_TAKE_OWNERSHIP_NAME
* SE_TCB_NAME
* SE_UNDOCK_NAME

Most services do not need such a high privilege level. If your service does not need these privileges, and it is not an interactive service, consider using the LocalService account or the NetworkService account.

### `SeAliasAdminsSid`

The SID that matches the administrator account.

### `SeAliasUsersSid`

The SID that matches built-in user accounts.

### `SeAliasGuestsSid`

The SID that matches the guest account.

### `SeAliasPowerUsersSid`

The SID that matches the power users group.

### `SeAliasAccountOpsSid`

The SID that matches the account operators account.

### `SeAliasSystemOpsSid`

The SID that matches the system operators group.

### `SeAliasPrintOpsSid`

The SID that matches the print operators group.

### `SeAliasBackupOpsSid`

The SID that matches the backup operators group.

### `SeAuthenticatedUsersSid`

The SID that matches any authenticated user.

### `SeRestrictedSid`

The SID for restricted code.

### `SeAnonymousLogonSid`

The SID for the anonymous account.

### `SeUndockPrivilege`

The privilege that is required to remove a computer from a docking station. This privilege allows the user of a portable computer to undock the computer by clicking **Start**, and then clicking **Eject PC**.

### `SeSyncAgentPrivilege`

The privilege that is required to synchronize directory service data. This privilege allows a process to read all objects and properties in the directory, regardless of the protection that is set on the objects and properties. This privilege is required in order to use Lightweight Directory Access Protocol (LDAP) directory synchronization (Dirsync) services. This privilege is required for a domain controller to use the LDAP directory synchronization services.

### `SeEnableDelegationPrivilege`

The privilege that is required to enable computer and user accounts to be trusted for delegation.

### `SeLocalServiceSid`

The SID that matches the LocalService account, a predefined local account. The LocalService account has minimum privileges on the local computer and presents anonymous credentials on the network. The name of the account in all locales is "NT AUTHORITY\LocalService". This account does not have a password. The LocalService account has its own subkey under the HKEY_USERS registry key. Therefore, the HKEY_CURRENT_USER registry key is associated with the LocalService account.

The LocalService account has the following privileges:

* SE_AUDIT_NAME
* SE_CHANGE_NOTIFY_NAME
* SE_UNDOCK_NAME
* Any privileges assigned to users and authenticated users

The LocalService account is available on the Microsoft Windows XP and later operating systems.

### `SeNetworkServiceSid`

The SID that matches the NetworkService account, a predefined local account. The NetworkService account has minimum privileges on the local computer and acts as the computer on the network. The name of the account in all locales is "NT AUTHORITY\NetworkService". This account does not have a password.

A service that runs in the context of the NetworkService account presents the computer's credentials to remote servers. By default, the remote token contains SIDs for the Everyone and Authenticated Users groups.

The NetworkService account has its own subkey under the HKEY_USERS registry key. Therefore, the HKEY_CURRENT_USER registry key is associated with the NetworkService account.

The NetworkService account has the following privileges:

* SE_AUDIT_NAME
* SE_CHANGE_NOTIFY_NAME
* SE_UNDOCK_NAME
* Any privileges assigned to users and authenticated users

### `SeManageVolumePrivilege`

The privilege that is required to allow a non-administrative or remote user to manage volumes or disks. The operating system checks for this privilege in a user's access token when a process running in the user's security context calls the user-mode [**SetFileValidData**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-setfilevaliddata) routine.

### `SeImpersonatePrivilege`

The privilege that is required to impersonate a user.

User-mode applications represent this privilege as the following user-right string: "Impersonate a client after authentication".

### `SeCreateGlobalPrivilege`

The privilege that is required for a user account to create global objects in a Terminal Services session. Note that users can still create session-specific objects without being assigned this user right. By default, this privilege is assigned to members of the Administrators group, the System account, and services that are started by the Service Control Manager. This privilege is available on Windows 2000 with Service Pack 4 and later.

User-mode applications represent this privilege as the following user-right string: "Create Global Objects".

### `SeTrustedCredManAccessPrivilege`

The privilege that is required to access Credential Manager as a trusted caller.

User-mode applications represent this privilege as the following user-right string: "Access Credential Manager as a trusted caller".

### `SeRelabelPrivilege`

The privilege that is required to modify the mandatory integrity level of an object.

User-mode applications represent this privilege as the following user-right string: "Modify an object label".

Available starting in Windows Vista.

### `SeIncreaseWorkingSetPrivilege`

The privilege that is required to allocate more memory for applications that run in the context of users.

User-mode applications represent this privilege as the following user-right string: "Increase a process working set".

Available starting in Windows Vista.

### `SeTimeZonePrivilege`

The privilege that is required to adjust the time zone associated with the computer's internal clock.

User-mode applications represent this privilege as the following user-right string: "Change the time zone".

Available starting in Windows Vista.

### `SeCreateSymbolicLinkPrivilege`

The SID that matches the IUSR built-in account and the IIS_IUSRS built-in group.

Available starting in Windows Vista.

### `SeIUserSid`

The SID for an untrusted integrity level.

Available starting in Windows Vista.

### `SeUntrustedMandatorySid`

The SID for an untrusted integrity level.

Available starting in Windows Vista.

### `SeLowMandatorySid`

The SID for a low integrity level.

Available starting in Windows Vista.

### `SeMediumMandatorySid`

The SID for a medium integrity level.

Available starting in Windows Vista.

### `SeHighMandatorySid`

The SID for a high integrity level.

Available starting in Windows Vista.

### `SeSystemMandatorySid`

The SID for a system integrity level.

Available starting in Windows Vista.

### `SeOwnerRightsSid`

The SID for a group that represents the current owner of the object.

Available starting in Windows Vista.

### `SeAllAppPackagesSid`

The SID for a group that represents all application packages. This SID is used to grant or deny permissions to all app packages installed on the system.

Available starting in Windows 8.

### `SeUserModeDriversSid`

The SID for a user-mode driver.

### `SeProcTrustWinTcbSid`

The SID that identifies its holder as a part of a trusted computer base. Such processes are considered highly privileged and trusted by the OS.

### `SeTrustedInstallerSid`

The SID for the Trusted Installer.

### `SeDelegateSessionUserImpersonatePrivilege`

Locally unique identifier (LUID) that represents the privilege to impersonate a user during session delegation.

### `SeAppSiloSid`

SID that represents an app silo, which is a security boundary within which Windows Store apps run.

### `SeAppSiloVolumeRootMinimalCapabilitySid`

SID that represents the minimal capabilities for accessing the profiles root within an app silo.

### `SeAppSiloProfilesRootMinimalCapabilitySid`

SID that represents the minimal capabilities for accessing the profiles root within an app silo.

### `SeAppSiloPromptForAccessCapabilitySid`

SID that represents the capability to prompt for access within an app silo.

### `SeAppSiloAccessToPublisherDirectoryCapabilitySid`

SID that represents the capability to access the publisher directory within an app silo.

## Remarks

**SeExports** is a large external static SE_EXPORTS structure exported by *Ntoskrnl.exe*.

## See also

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**SID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)