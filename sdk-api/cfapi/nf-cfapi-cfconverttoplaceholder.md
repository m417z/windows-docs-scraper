# CfConvertToPlaceholder function

## Description

Converts an existing non-placeholder file or directory under a sync root directory tree to a placeholder. This is useful, for example, after a new local file or directory appears on a client and the sync provider has finished syncing it to the cloud. Note that there are no parameters for passing in file system metadata (timestamps, file size, etc.); those are taken verbatim from the local file.

## Parameters

### `FileHandle` [in]

Handle to the file or directory to be converted.

### `FileIdentity` [in, optional]

A user mode buffer that contains the opaque file or directory information supplied by the caller. Optional if the caller is not dehydrating the file at the same time, or if the caller is converting a directory. *FileIdentity* gets passed back to the sync provider in all callbacks. Cannot exceed 4KB in size.

### `FileIdentityLength` [in]

Length, in bytes, of the *FileIdentity*.

### `ConvertFlags` [in]

Placeholder conversion flags. *ConvertFlags* can be set to the following values:

| Flag | Description |
|--------|--------|
| **CF_CONVERT_FLAG_MARK_IN_SYNC** | If this is specified, the platform marks the converted placeholder as in sync with cloud upon a successful conversion of the file. |
| **CF_CONVERT_FLAG_DEHYDRATE** | This is applicable for files only. When specified, the platform dehydrates the file after converting it to a placeholder successfully. The caller must acquire an exclusive handle when specifying this flag or data corruptions can occur. Note that the platform does not validate the exclusiveness of the handle. |
| **CF_CONVERT_FLAG_ENABLE_ON_DEMAND_POPULATION** | This is applicable for directories only. When specified, it marks the converted placeholder directory partially populated such that any future access to it will result in a **FETCH_PLACEHOLDERS** callback sent to the sync provider. |
| **CF_CONVERT_FLAG_ALWAYS_FULL** | This is effective on placeholder files only. Once a file is converted to a placeholder with this flag, the placeholder is marked always full. Any attempt to dehydrate such a placeholder will fail with error code **ERROR_CLOUD_FILE_DEHYDRATION_DISALLOWED**. |
| **CF_CONVERT_FLAG_FORCE_CONVERT_TO_CLOUD_FILE** | When specified, the platform allows a sync engine to atomically convert a non-cloud files placeholder (having another reparse tag/data) to a cloud files placeholder. Note that the API normally fails conversion of any non-placeholder file to a placeholder.<br><br>The combination **(CF\_CONVERT\_FLAG\_FORCE\_CONVERT\_TO\_CLOUD\_FILE \| CF\_CONVERT\_FLAG\_DEHYDRATE)** is especially useful in migration scenarios when certain providers are migrating from another platform to cloud files platform and they intend to convert hydrated placeholders on the older platform to dehydrated placeholders on the cloud files platform atomically. Just this flag should be passed for converting full placeholders to cloud files placeholders. If the older platform implements full files as a regular, non-placeholder files, this flag is not needed. Passing this flag on a directory converts directories to cloud files as well, though the **DEHYDRATE** flag doesn’t apply to directories.<br><br>Even when the policy **CF\_PLACEHOLDER\_MANAGEMENT\_POLICY\_CONVERT\_TO\_UNRESTRICTED** was specified with [CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot), only processes that have registered/connected to the cloud files sync root are allowed to specify this flag.<br><br>**Note:** The flag is supported only if the `PlatformVersion.IntegrationNumber` obtained from [CfGetPlatformInfo](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplatforminfo) is `0x500` or higher. |

### `ConvertUsn` [out, optional]

When specified, this is the final USN value after convert actions are performed.

### `Overlapped` [in, out, optional]

When specified and combined with an asynchronous *FileHandle*, *Overlapped* allows the platform to perform the **CfConvertToPlaceholder** call asynchronously. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconverttoplaceholder#-remarks) for more details.

If not specified, the platform will perform the API call synchronously, regardless of how the handle was created.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the file case, the caller must acquire an exclusive handle to the file if it also intends to dehydrate the file at the same time or data corruption can occur. To minimize the impact on user applications it is highly recommended that the caller obtain the exclusiveness using proper oplocks (via [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock)) as opposed to using a share-nothing handle.

To convert a placeholder:

- The file or directory to be converted must be contained in a registered sync root tree; it can be the sync root directory itself, or any descendant directory; otherwise, the call with be failed with **HRESULT(ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT)**.
- If dehydration is requested, the sync root must be registered with a valid hydration policy that is not **CF_HYDRATION_POLICY_ALWAYS_FULL**; otherwise the call will be failed with **HRESULT(ERROR_CLOUD_FILE_NOT_SUPPORTED)**.
- If dehydration is requested, the placeholder must not be pinned locally or the call with be failed with **HRESULT(ERROR_CLOUD_FILE_PINNED)**.
- If dehydration is requested, the placeholder must be in sync or the call with be failed with **HRESULT(ERROR_CLOUD_FILE_NOT_IN_SYNC)**.
- The caller must have **WRITE_DATA** or **WRITE_DAC** access to the file or directory to be converted. Otherwise the operation will be failed with **HRESULT(ERROR_CLOUD_FILE_ACCESS_DENIED)**.

If the API returns **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** when using *Overlapped* asynchronously, the caller can then wait using [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult).

## See also

[CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock)

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)