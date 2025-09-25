# IWDFDriverCreatedFile::Close

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Close** method closes an instance of a UMDF driver-created-file object that was created by calling the [IWDFDevice::CreateWdfFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createwdffile) method.

## Remarks

For more information, see [Creating and Using Driver-Created File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-and-using-driver-created-file-objects).

## See also

[IWDFDevice::CreateWdfFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createwdffile)

[IWDFDriverCreatedFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdrivercreatedfile)