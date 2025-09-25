# IWDFMemory::GetDataBuffer

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **GetDataBuffer** method retrieves the data buffer that is associated with a memory object.

## Parameters

### `BufferSize` [out, optional]

A pointer to a variable that receives information that describes the size of the data buffer.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## Return value

**GetDataBuffer** returns a pointer to the data buffer.

## Remarks

For a code example of how to use the **GetDataBuffer** method, see [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate).

## See also

- [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)
- [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate)