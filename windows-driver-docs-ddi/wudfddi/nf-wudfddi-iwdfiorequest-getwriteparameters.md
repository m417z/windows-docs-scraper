# IWDFIoRequest::GetWriteParameters

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **GetWriteParameters** method retrieves the request parameters for a write-type request.

## Parameters

### `pSizeInBytes` [out, optional]

A pointer to a variable that receives the size, in bytes, to write. To retrieve the data for writing, the driver calls the [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) method.

This parameter is optional. The driver can pass **NULL** if it does not require the information.

### `pullOffset` [out, optional]

A pointer to a variable that receives the offset, in bytes, to begin writing to the device or the file on the device. If the device does not support absolute write addresses, *pullOffset* can be ignored. For more information, see the following Remarks section.

Client applications specify this value in the **Offset** and **OffsetHigh** members of the OVERLAPPED structure. A pointer to OVERLAPPED is passed in the Microsoft Win32 **WriteFile** or **WriteFileEx** function.

This parameter is optional. The driver can pass **NULL** if it does not require the information.

### `pulKey` [out, optional]

A pointer to a variable that receives a key that the driver can use to sort the I/O request in a way that the driver determines.

This parameter is optional. The driver can pass **NULL** if it does not require the information.

## Remarks

A call to **GetWriteParameters** fails if the request type is not a write type.

For devices that support addressing (for example, a disk device), the value that the *pullOffset* parameter points to is typically the byte offset into the device. For devices that do not support addressing (for example, a serial port), the driver can ignore the value at *pullOffset*.

## See also

- [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)
- [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory)