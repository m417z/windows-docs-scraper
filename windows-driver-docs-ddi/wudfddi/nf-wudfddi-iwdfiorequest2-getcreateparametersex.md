# IWDFIoRequest2::GetCreateParametersEx

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetCreateParametersEx** method retrieves file creation parameters that are associated with a file that is being created or opened.

## Parameters

### `pOptions` [out, optional]

A pointer to a caller-allocated variable that receives bit flags that indicate file creation options. These FILE_XXXX-named bit flags are defined in Wdm.h.

The low 24 bits of the variable indicate options to apply when creating or opening the file. For more information about these bits, see the description of the *CreateOptions* parameter of the kernel-mode [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) function.

The high eight bits of the variable indicate actions to perform if the file does or does not already exist. For more information about these bits, see the description of the *CreateDisposition* parameter of **ZwCreateFile**.

This parameter is optional and can be **NULL**.

### `pFileAttributes` [out, optional]

A pointer to a caller-allocated variable that receives bit flags that indicate file attributes. These FILE_ATTRIBUTE_XXXX-named bit flags are defined in Wdm.h. For more information about these bit flags, see the description of the *FileAttributes* parameter of **ZwCreateFile**.

This parameter is optional and can be **NULL**.

### `pShareAccess` [out, optional]

A pointer to a caller-allocated variable that receives bit flags that indicate file sharing options. These FILE_SHARE_XXXX-named bit flags are defined in Wdm.h. For more information about these bit flags, see the description of the *ShareAccess* parameter of [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

This parameter is optional and can be **NULL**.

### `pDesiredAccess` [out, optional]

A pointer to a caller-allocated [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) structure that specifies the requested access to the file. For more information about this parameter, see the *DesiredAccess* parameter of **ZwCreateFile**.

This parameter is optional and can be **NULL**.

## Remarks

After the framework calls a driver's [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function, the driver can call the [IWDFIoRequest::GetCreateParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcreateparameters) method or the **IWDFIoRequest2::GetCreateParametersEx** method to obtain the file's creation parameters.

For more information, see [Obtaining Parameters for I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-parameters-for-i-o-requests).

#### Examples

The following code example shows how an [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function can obtain the [IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2) interface and then call **GetCreateParametersEx**.

```
VOID
OnCreateFile(
    __in IWDFIoQueue* FxQueue,
    __in IWDFIoRequest* FxRequest,
    __in IWDFFile* FxFile
    )
{
    ULONG fileOptions;
    USHORT fileAttributes,
    USHORT shareAccess,
    ACCESS_MASK desiredAccess;
    ...
    CComQIPtr<IWDFIoRequest2> fxRequest2(FxRequest);
    fxRequest2->GetCreateParametersEx(&fileOptions
                                      &fileAttributes,
                                      &shareAccess,
                                      &desiredAccess);
    ...
}
```

## See also

[IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest::GetCreateParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getcreateparameters)