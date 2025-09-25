# IWDFRemoteTarget::OpenFileByName

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OpenFileByName** method opens a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf) that is a file.

## Parameters

### `pszFileName` [in]

A pointer to a caller-supplied, **null**-terminated string that represents the name of the file to open. For more information about this member, see the *FileName* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `DesiredAccess` [in]

A bitmask that specifies the caller's desired access to the file. For more information about this member, see the *dwDesiredAccess* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `pOpenParams` [in, optional]

A pointer to a caller-allocated [UMDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ns-wudfddi-_umdf_io_target_open_params) structure that contains additional parameters. This parameter is optional and can be **NULL**.

## Return value

**OpenFileByName** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |

This method might return one of the other values that Winerror.h contains.

The framework's [verifier](https://learn.microsoft.com/windows-hardware/drivers/debugger/-verifier) reports an error if the framework cannot open the file.

## Remarks

Your driver can use **OpenFileByName** to open a file, if the driver stack to which your driver belongs does not support the file's device. Use [IWDFFileHandleTargetFactory::CreateFileHandleTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffilehandletargetfactory-createfilehandletarget) to open a file, if the driver stack to which your driver belongs does support the file's device.

The specified file must be accessible by the account that loaded the UMDF-based driver, which is typically the Local Service account. However, if the driver uses [impersonation](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers) when it calls **OpenFileByName**, the file must be accessible by the impersonated account.

Do not call **OpenFileByName** to open a remote target to a control device object. Instead, open the control device directly by calling [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea).

For more information about the **OpenFileByName** method and remote I/O targets, see [General I/O Targets in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

#### Examples

The following code example creates a remote target object and opens an existing file with read-only access.

```
UMDF_IO_TARGET_OPEN_PARAMS openParams;
HRESULT hr;

//
// Create a new remote target object and provide a callback
// object to handle remote target events.
//
CComPtr<IWDFRemoteTarget> fxTarget;
hr = FxDevice->CreateRemoteTarget(MyRemoteTargetIUnknown,
                                  fxRemoteInterface,
                                  &fxTarget);
if (FAILED(hr)) goto Error;

//
// Open existing file for read-only access.
//
openParams.dwShareMode = 0;
openParams.dwCreationDisposition = OPEN_EXISTING;
openParams.dwFlagsAndAttributes = FILE_ATTRIBUTE_READONLY;

hr = fxTarget->OpenFileByName(FILE_PATH,
                              GENERIC_READ,
                              &openParams);

```

## See also

[IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget)

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface)