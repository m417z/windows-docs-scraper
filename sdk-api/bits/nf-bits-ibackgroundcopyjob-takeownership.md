# IBackgroundCopyJob::TakeOwnership

## Description

Changes ownership of the job to the current user.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Job ownership was successfully changed. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |
| **BG_E_NEW_OWNER_NO_FILE_ACCESS** | The new owner has insufficient access to the temporary files on the client computer. BITS creates the temporary files using the owner's security permissions. |
| **BG_E_NEW_OWNER_DIFF_MAPPING** | The current owner's network drive mapping for the local file is different from the previous owner's. |
| **E_ACCESSDENIED** | User does not have administrator privileges. |

## Remarks

To take ownership of the job, the user must have administrator privileges on the client. On Windows Vista, the user must run in an elevated state. After taking ownership, any future updates to the job must be done while the user is running in an elevated state. For details, see [Users and Network Connections](https://learn.microsoft.com/windows/desktop/Bits/users-and-network-connections).

An administrator does not have to take ownership of another user's job to change its properties or to add files to the job. Typically, an administrator uses the
**TakeOwnership** method if the user does not have sufficient permission to complete the job or if the user is not logged on and the administrator needs the job to complete.

After ownership of the job has changed, the job is processed only when the new owner is logged on to the client. Call the
[IBackgroundCopyJob::GetOwner](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getowner) method to retrieve the SID of the new owner.

If the administrator
[cancels](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) the job after taking ownership, it is possible that the files may be orphaned because the administrator does not have write permission to the files. This can occur if the local file destination is in the previous user's roaming profile.

The
**TakeOwnership** method removes
[credentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials), [certificates](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid), [custom headers](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setcustomheaders), and
[command line notification](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) from the job, if set.

If the job specifies [event notification](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface), the callback is executed in the context of the user who called the **IBackgroundCopyJob::SetNotifyInterface** method.

## See also

[IBackgroundCopyJob::GetOwner](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getowner)