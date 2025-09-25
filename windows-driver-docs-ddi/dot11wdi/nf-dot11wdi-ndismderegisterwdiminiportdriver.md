# NdisMDeregisterWdiMiniportDriver function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

A miniport driver calls the NdisMDeregisterWdiMiniportDriver function to release resources that it allocated with a previous call to the [NdisMRegisterWdiMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nf-dot11wdi-ndismregisterwdiminiportdriver) function.

## Parameters

### `NdisMiniportDriverHandle` [in]

The NDIS handle for a miniport driver.

## Return value

This function does not return a value.

## See also

[NdisMRegisterWdiMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nf-dot11wdi-ndismregisterwdiminiportdriver)