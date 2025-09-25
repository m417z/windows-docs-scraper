# WlanFreeMemory function

## Description

The **WlanFreeMemory** function frees memory. Any memory returned from Native Wifi functions must be freed.

## Parameters

### `pMemory` [in]

Pointer to the memory to be freed.

## Remarks

If *pMemory* points to memory that has already been freed, an access violation or heap corruption may occur.

There is a hotfix available for Wireless LAN API for Windows XP with Service Pack 2 (SP2) that can help improve the performance of applications that call **WlanFreeMemory** and [WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist) many times.

## See also

[WlanAllocateMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanallocatememory)