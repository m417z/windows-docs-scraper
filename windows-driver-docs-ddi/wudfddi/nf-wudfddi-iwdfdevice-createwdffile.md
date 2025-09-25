# IWDFDevice::CreateWdfFile

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateWdfFile** method creates a file object for a driver to use.

## Parameters

### `pcwszFileName` [in, optional]

A pointer to a **NULL**-terminated string that contains the name of the file to create a file object from. This parameter is optional. The driver can pass **NULL** if the driver does not have to create the file object from a file name. If the driver must supply a name, the string that the driver passes must not contain any path separator characters ("/" or "\\").

### `ppFile` [out]

A pointer to a buffer that receives a pointer to the [IWDFDriverCreatedFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdrivercreatedfile) interface for the driver-created file object.

## Return value

**CreateWdfFile** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

For information about when a UMDF driver uses **CreateWdfFile** to handle I/O, see [Creating a File Object to Handle I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-file-object-to-handle-i-o).

For information about when a UMDF driver might use **CreateWdfFile** to prevent an imbalance of create and close notifications to a driver, see [Preventing an Imbalance of Create and Close Notifications to a Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/preventing-an-imbalance-of-create-and-close-notifications-to-a-driver).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriverCreatedFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdrivercreatedfile)