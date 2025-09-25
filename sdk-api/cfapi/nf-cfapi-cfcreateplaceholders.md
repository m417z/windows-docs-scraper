# CfCreatePlaceholders function

## Description

Creates one or more new placeholder files or directories under a sync root directory tree.

## Parameters

### `BaseDirectoryPath` [in]

Path to the local directory in which the placeholders are created. Keep the following in mind when specifying the path:

- This path must be contained in a registered sync root tree. It can be the sync root directory itself, or any descendant directory. Otherwise, the call will fail with **STATUS_CLOUD_FILE_NOT_UNDER_SYNC_ROOT**.
- The sync root must be registered with a valid hydration policy that is not **CF_HYDRATION_POLICY_ALWAYS_FULL**, otherwise the call will fail with **STATUS_CLOUD_FILE_NOT_SUPPORTED**.
- The caller must have **WRITE_DATA** or **WRITE_DAC** access to the base directory under which the placeholder is about to be created. Otherwise the operation will be failed with **STATUS_CLOUD_FILE_ACCESS_DENIED**.

### `PlaceholderArray` [in, out]

On successful creation, the *PlaceholderArray* contains the final USN value and a `STATUS_OK` message. On return, this array contains an **HRESULT** value describing whether the placeholder was created or not. *PlaceholderArray* points to an array of placeholders to be created, relative to *BaseDirectoryPath*. Each entry in the array includes the following fields:

- **RelativeFileName** is the name of the child placeholder, both file and directory, to be created.
- **FsMetadata** contains file system metadata about the placeholder to be created, including all timestamps, file attributes and file size (*optional for directories*).
- **FileIdentity** and **FileIdentityLength** describe a user mode buffer that contains the opaque file information supplied by the sync provider. The **FileIdentity** blob should not exceed **CF_PLACEHOLDER_MAX_FILE_IDENTITY_LENGTH** (defined to 4KB) in size. **FileIdentity** gets passed back to the sync provider in all callbacks. This is a mandatory field for files.

A sync provider can choose the following flags or a combination of them on a per-placeholder basis:

- **CF_PLACEHOLDER_CREATE_FLAG_DISABLE_ON_DEMAND_POPULATION** - This flag is applicable for a child placeholder directory only. When the flag is present, the newly created child placeholder directory is considered to have all of its children present locally hence accessing it in the future will not trigger any **FETCH_PLACEHOLDERS** callback on it. When the flag is absent, the newly created placeholder directory is considered partial and future access will trigger **FETCH_PLACEHOLDERS**.
- **CF_PLACEHOLDER_CREATE_FLAG_MARK_IN_SYNC** - This flag is applicable for both placeholder files and directories. When this flag is present, the newly created placeholder will be marked as in-sync as part of the **TRANSFER_PLACEHOLDERS** operation.
- **CF_PLACEHOLDER_CREATE_FLAG_ALWAYS_FULL** - This flag is enforced on a placeholder file only. It can be set on a placeholder directory, but it has no effect. When this flag is present, the newly created placeholder will be marked as always full. Once hydrated, any attempt to dehydrate such a file placeholder will fail with error code **ERROR_CLOUD_FILE_DEHYDRATION_DISALLOWED**.

### `PlaceholderCount` [in]

The count of placeholders in the *PlaceholderArray*.

### `CreateFlags` [in]

Flags for configuring the creation of a placeholder. *CreateFlags* can be set to the following values:

- **CF_CREATE_FLAG_NONE** is the default mode where the API processes all entries in the array even when errors are encountered.
- **CF_CREATE_FLAG_STOP_ON_ERROR** causes the API to return immediately if creation of a placeholder fails. In that case, the API returns the failure code.

### `EntriesProcessed` [out]

The number of entries processed, including failed entries. If **CF_CREATE_FLAG_STOP_ON_ERROR** was not specified in *CreateFlags*, the API returns the first failure code encountered, but continues processing as many entries as possible; the caller must then inspect the array to see which placeholder creation(s) failed.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creating a placeholder with this function is preferred compared to creating a new file with [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) and then converting it to a placeholder with [CfConvertToPlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconverttoplaceholder); both for efficiency and because it eliminates the time window where the file is not a placeholder. The function can also create multiple files or directories in a batch, which can also be more efficient.

This function is useful when performing an initial sync of files or directories from the cloud down to the client, or when syncing down a newly created single file or directory from the cloud.

## See also

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)

[CfConvertToPlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconverttoplaceholder)