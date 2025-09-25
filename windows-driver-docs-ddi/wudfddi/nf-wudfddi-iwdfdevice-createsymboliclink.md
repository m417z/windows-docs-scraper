# IWDFDevice::CreateSymbolicLink

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateSymbolicLink** method creates a symbolic link for the device.

## Parameters

### `pSymbolicLink` [in]

A pointer to a **NULL**-terminated string that contains the name of the symbolic link for the device. The symbolic link name must be in the global **DosDevices** namespace.

## Return value

**CreateSymbolicLink** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

 A symbolic link is a file-system object that points to another file-system object. The object being pointed to is called the target.

For an example usage of this method, see the [VirtualSerial](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-mode-driver-framework-design-guide) driver sample.

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDevice2::CreateSymbolicLinkWithReferenceString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createsymboliclinkwithreferencestring)