# IWDFDevice::GetDriver

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDriver** method retrieves the interface to the parent driver object of a device instance.

## Parameters

### `ppWdfDriver` [out]

A pointer to a variable that receives a pointer to the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface for the parent driver object.

## Remarks

For a code example of how to use the GetDriver method, see [IWDFDriver::CreateWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfmemory).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)