# _UMDF_IO_TARGET_OPEN_PARAMS structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **UMDF_IO_TARGET_OPEN_PARAMS** structure contains file-open parameters.

## Members

### `dwShareMode`

The type of sharing to allow for the file. For more information about this member, see the *dwShareMode* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `dwCreationDisposition`

The action to take if the file already exists. For more information about this member, see the *dwCreationDisposition* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `dwFlagsAndAttributes`

Additional flags and attributes for the file. For more information about this member, see the *dwFlagsAndAttributes* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

## Remarks

The **UMDF_IO_TARGET_OPEN_PARAMS** structure is used as input to [IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname) and [IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface).

## See also

[IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname)

[IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface)