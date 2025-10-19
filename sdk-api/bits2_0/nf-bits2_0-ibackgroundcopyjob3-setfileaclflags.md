# IBackgroundCopyJob3::SetFileACLFlags

## Description

Specifies the owner and ACL information to maintain when using SMB to download or upload a file.

## Parameters

### `Flags` [in]

Flags that identify the owner and ACL information to maintain when transferring a file using SMB. Subsequent calls to this method overwrite the previous flags. Specify 0 to remove the flags from the job. You can specify any combination of the following flags.

| Value | Meaning |
| --- | --- |
| **BG_COPY_FILE_OWNER** | If set, the file's owner information is maintained. Otherwise, the user who calls the [Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method owns the file.<br><br>You must have SeRestorePrivilege to set this flag. The administrators group contains the SeRestorePrivilege privilege. |
| **BG_COPY_FILE_GROUP** | If set, the file's group information is maintained. Otherwise, BITS uses the job owner's primary group to assign the group information to the file.<br><br>You must have SeRestorePrivilege to set this flag. The administrators group contains the SeRestorePrivilege privilege. |
| **BG_COPY_FILE_DACL** | If set, BITS copies the explicit ACEs from the source file and inheritable ACEs from the destination folder. Otherwise, BITS copies the inheritable ACEs from the destination folder. If the destination folder does not contain inheritable ACEs, BITS uses the default DACL from the owner's account. |
| **BG_COPY_FILE_SACL** | If set, BITS copies the explicit ACEs from the source file and inheritable ACEs from the destination folder. Otherwise, BITS copies the inheritable ACEs from the destination folder.<br><br>You must have SeSecurityPrivilege on both the local and remote computers to set this flag. The administrators group contains the SeSecurityPrivilege privilege. |
| **BG_COPY_FILE_ALL** | If set, BITS copies the owner and ACL information. This is the same as setting all the flags individually. |

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully set the flags. |
| **BG_E_INVALID_STATE** | You must call this method before the job transitions to the [BG_JOB_STATE_TRANSFERRED](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_state) state. |
| **E_INVALIDARG** | The *Flags* parameter contains a flag that is not in the list. |

## Remarks

These flags apply to remote file names that specify the SMB protocol. BITS ignores the flags for HTTP transfers.

BITS propagates the file time stamps and attributes (not extended attributes) for SMB files.

BITS applies the owner and ACL information to the file at the time the file transfer is complete, not when it [creates](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) the temporary transfer file. BITS does not specify a security descriptor when it creates the temporary transfer file (the file inherits the ACL information from the destination directory). If the transferred data is sensitive, the application should specify an appropriate ACL on the destination directory to prevent unauthorized access.

To ensure the proper owner and ACL information is set on all files in the job, call this method after you create the job and before calling the [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method. Otherwise, those files that transferred before the flags were set will not contain the appropriate owner and ACL information.

This method is modeled after the XCopy DOS command.

The owner and ACL information is not maintained if you download to a FAT file system.

If the user does not have privileges on the local and remote computers to copy the owner or ACL information, BITS places the job in a transient error state and sets the error code to **E_ACCESSDENIED**.

#### Examples

The following example shows how to call the **SetFileACLFlags** method to specify what owner and ACL information to maintain with the files that BITS downloads. The example assumes the [IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) variable, pJob, is valid, points to a new job, and is suspended.

```cpp
     IBackgroundCopyJob *pJob;
     IBackgroundCopyJob3 *pJob3 = NULL;

     //Need to query the IBackgroundCopyJob interface for an IBackgroundCopyJob3
     //interface pointer. The IBackgroundCopyJob3 interface contains the SetACLFlags method.
     hr = pJob->QueryInterface(__uuidof( IBackgroundCopyJob3 ), (void**)&pJob3;);
     if (S_OK == hr)
     {
          pJob->Release(); //No longer need the IBackgoundCopyJob interface pointer.

          //Copy the group and DACL information for each file.
          hr = pJob3->SetACLFlags(BG_COPY_FILE_GROUP | BG_COPY_FILE_DACL);
          if (FAILED(hr))
          {
               //Handle error.
          }

          ... //Add one or more files and resume the job.
          pJob3->Resume();

          //When done, release the interface pointer.
          pJob3->Release();
     }
     else
     {
          //Handle error. QueryInterface will return E_NOINTERFACE if the version of BITS
          //running on the computer is less than BITS 2.0.
     }
```

## See also

[IBackgroundCopyJob3](https://learn.microsoft.com/windows/desktop/api/bits2_0/nn-bits2_0-ibackgroundcopyjob3)

[IBackgroundCopyJob3::GetFileACLFlags](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-getfileaclflags)