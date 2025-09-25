# IDriverEntry::OnDeinitialize

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnDeinitialize** method performs any operations that are necessary before a system unloads a driver.

## Parameters

### `pWdfDriver` [in]

A pointer to the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface for the driver object that represents the driver that the system unloads.

## Remarks

The framework creates a new driver object for each driver that is loaded in the driver host process. When a driver is about to be unloaded from the host process, the framework calls **OnDeinitialize** to notify the driver of the departure and passes the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface in the call. The system unloads the driver after **OnDeinitialize** returns.

## See also

[IDriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-idriverentry)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)