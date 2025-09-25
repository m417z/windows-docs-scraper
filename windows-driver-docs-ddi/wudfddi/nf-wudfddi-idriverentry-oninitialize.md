# IDriverEntry::OnInitialize

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnInitialize** method performs any operations that are necessary to initialize a driver.

## Parameters

### `pWdfDriver` [in]

A pointer to the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface for the framework driver object that represents the driver that is loaded in the host process.

## Return value

**OnInitialize** returns S_OK if the driver completed its global initialization. Otherwise, this method returns one of the error codes that are defined in Winerror.h. If the driver returns an error code, the framework will not load the driver.

## Remarks

The framework creates a new driver object for each driver that is loaded in the driver host process. When a driver enters the system, the framework calls **OnInitialize** to notify the driver and passes the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface in the call.

## See also

[IDriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-idriverentry)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)