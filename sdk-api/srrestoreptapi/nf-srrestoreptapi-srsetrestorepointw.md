# SRSetRestorePointW function

## Description

Specifies the beginning and the ending of a set of changes so that System Restore can create a restore point.

For a scriptable equivalent, see
[CreateRestorePoint](https://learn.microsoft.com/windows/desktop/sr/createrestorepoint-systemrestore).

## Parameters

### `pRestorePtSpec` [in]

A pointer to a
[RESTOREPOINTINFO](https://learn.microsoft.com/windows/win32/api/srrestoreptapi/ns-srrestoreptapi-restorepointinfoa) structure that specifies the restore point.

### `pSMgrStatus` [out]

A pointer to a
[STATEMGRSTATUS](https://learn.microsoft.com/windows/win32/api/srrestoreptapi/ns-srrestoreptapi-statemgrstatus) structure that receives the status information.

## Return value

If the function succeeds, the return value is **TRUE**. The **llSequenceNumber** member of *pSMgrStatus* receives the sequence number of the restore point.

If the function fails, the return value is **FALSE**. The **nStatus** member of *pSMgrStatus* receives error information.

## Remarks

You must initialize COM security to allow NetworkService, LocalService and System to call back into any process that uses **SRSetRestorePoint**. This is necessary for **SRSetRestorePoint** to operate properly. For information on setting up the COM calls to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) and [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity), see [Using System Restore](https://learn.microsoft.com/windows/desktop/sr/using-system-restore).

This function cannot be called in safe mode. It also fails if System Restore has been disabled (see
[Disable](https://learn.microsoft.com/windows/desktop/sr/disable-systemrestore)).

When you call this function, System Restore takes a full snapshot of the registry and other system databases.

Applications should not call System Restore functions using load-time dynamic linking. Instead, use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load SrClient.dll and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to call the function.

Create restore points just prior to a system change, by calling
**SRSetRestorePoint** with the **dwEventType** member of the
[RESTOREPOINTINFO](https://learn.microsoft.com/windows/win32/api/srrestoreptapi/ns-srrestoreptapi-restorepointinfoa) structure set to BEGIN_SYSTEM_CHANGE. After the changes to the system have been completed, call
**SRSetRestorePoint** with **dwEventType** set to END_SYSTEM_CHANGE.

If the user cancels the application installation, the installer may remove the restore point it created when the installation began. Removing the restore point is optional and can prevent the user from recovering from unintentional changes made by the installer during the cancellation. If the installer is to remove a restore point, it can call the
[SRRemoveRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srremoverestorepoint) function, or call
**SRSetRestorePoint** with **dwRestorePointType** set to CANCELLED_OPERATION, **dwEventType** set to END_SYSTEM_CHANGE, and **llSequenceNumber** set to the value returned by the initial call to **SRSetRestorePoint**.

Be careful when making nested calls to
**SRSetRestorePoint**. For more information, see
[Nested calls to SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/sr/nested-calls-to-srsetrestorepoint).

**Windows 8:**

A new registry key enables application developers to change the frequency of restore-point creation.

Applications should create this key to use it because it will not preexist in the system. The following applies by default if the key does not exist. If an application calls the **SRSetRestorePoint** function to create a restore point, Windows skips creating this new restore point if any restore points have been created in the last 24 hours. System Restore sets the **IISequenceNumber** member of the [STATEMGRSTATUS](https://learn.microsoft.com/windows/win32/api/srrestoreptapi/ns-srrestoreptapi-statemgrstatus) structure to the sequence number for the restore point created previously in the day and sets the value of the **nStatus** member to **ERROR_SUCCESS**.

The **SRSetRestorePoint** function returns **TRUE**.

Developers can write applications that create the **DWORD** value **SystemRestorePointCreationFrequency** under the registry key **HKLM\Software\Microsoft\Windows NT\CurrentVersion\SystemRestore**. The value of this registry key can change the frequency of restore point creation.

If the application calls **SRSetRestorePoint** to create a restore point, and the registry key value is 0, system restore does not skip creating the new restore point.

If the application calls **SRSetRestorePoint** to create a restore point, and the registry key value is the integer N, system restore skips creating a new restore point if any restore points were created in the previous N minutes.

**Windows 8:**

System Restore running on Windows 8 monitors files in the boot volume that are relevant for system restore only. Snapshots of the boot volume created by System Restore running on Windows 8 may be deleted if the snapshot is subsequently exposed by an earlier version of Windows. Note that although there is only one system volume, there is one boot volume for each operating system in a multi-boot system.

Developers can write applications that create the **DWORD** value **ScopeSnapshots** under the registry key **HKLM\Software\Microsoft\Windows NT\CurrentVersion\SystemRestore**. If this registry key value is 0, System Restore creates snapshots of the boot volume in the same way as in earlier versions of Windows. If this value is deleted, System Restore running on Windows 8 resumes creating snapshots that monitor files in the boot volume that are relevant for system restore only.

#### Examples

For an example, see [Using System Restore](https://learn.microsoft.com/windows/desktop/sr/using-system-restore).

> [!NOTE]
> The srrestoreptapi.h header defines SRSetRestorePoint as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SRRemoveRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srremoverestorepoint)