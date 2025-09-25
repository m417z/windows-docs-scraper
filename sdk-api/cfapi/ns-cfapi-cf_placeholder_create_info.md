# CF_PLACEHOLDER_CREATE_INFO structure

## Description

Contains placeholder information for creating new placeholder files or directories.

## Members

### `RelativeFileName`

The name of the child placeholder file or directory to be created. It should consist only of the file or directory name.

For example, if the sync root of the provider is C:\SyncRoot then to create a placeholder named placeholder.txt in a subdirectory of the sync root, call the [CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders) function with *BaseDirectoryPath* equal to `C:\SyncRoot\SubDirectory` and set the *RelativePathName* field of the **CF_PLACEHOLDER_CREATE_INFO** to `placeholder.txt`.

### `FsMetadata`

File system metadata to be created with the placeholder, including all timestamps, file attributes and file size (optional for directories).

### `FileIdentity`

A user mode buffer containing file information supplied by the sync provider. The *FileIdentity* blob should not exceed **CF_PLACEHOLDER_MAX_FILE_IDENTITY_LENGTH** (defined to 4KB) in size. *FileIdentity* gets passed back to the sync provider in all callbacks. This is required for files (not for directories).

### `FileIdentityLength`

Length, in bytes, of the *FileIdentity*.

### `Flags`

Flags for specifying placeholder creation behavior. See [CF_PLACEHOLDER_CREATE_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_create_flags) for more information.

### `Result`

The result of placeholder creation. On successful creation, the value is **STATUS_OK**.

### `CreateUsn`

The final USN value after create actions are performed.

## See also

[CF_PLACEHOLDER_CREATE_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_create_flags)

[CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders)