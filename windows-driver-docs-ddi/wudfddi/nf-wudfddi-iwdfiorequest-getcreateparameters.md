# IWDFIoRequest::GetCreateParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetCreateParameters** method retrieves the request parameters for a create-type request.

## Parameters

### `pOptions` [out, optional]

A pointer to a variable that receives a bitmask of flags that specify the options that are applied when creating or opening the file that is associated with the request and the action to be taken if the file already exists.

The high 8 bits of this parameter correspond to the *CreateDisposition* parameter of the kernel-mode [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) function. These 8 bits specify the action to be taken, depending on whether the file already exists. Note that these disposition values differ from the values that are used in the *dwCreationDisposition* parameter of the Win32 **CreateFile** function.

The low 24 bits of this parameter correspond to the *CreateOptions* parameter of [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pFileAttributes` [out, optional]

A pointer to a variable that receives a bitmask of attribute flags that is applied when creating or opening the file that is associated with the request. Explicitly specified attributes are applied only when the file is created, superseded, or, in some situations, overwritten. By default, the single FILE_ATTRIBUTE_NORMAL flag is specified. However, this flag can be overridden by any other flag or by a bitwise OR combination of compatible flags. The bitmask of attribute flags corresponds to the *FileAttributes* parameter of [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pShareAccess` [out, optional]

A pointer to a variable that receives a bitmask of flags that specify the share access rights that are requested for the file that is associated with the request. If the received bitmask is zero, exclusive access is being requested. For more information about share access, see the description of the *ShareAccess* parameter of [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## Remarks

Although the driver can optionally specify **NULL** for each of the *pOptions*, *pFileAttributes*, and *pShareAccess* parameters, the driver must specify at least one non-**NULL** parameter for **GetCreateParameters** to execute successfully.

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)