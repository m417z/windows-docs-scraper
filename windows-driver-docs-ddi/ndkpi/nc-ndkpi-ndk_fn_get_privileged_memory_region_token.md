# NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN callback function

## Description

The *NdkGetPrivilegedMemoryRegionToken* (*NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN*) function gets an NDK privileged memory region token.

## Parameters

### `pNdkPd` [in]

A pointer to an NDK protection domain (PD) object ([NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)).

### `pToken` [out]

A memory token value is returned in this location.

## Remarks

*NdkGetPrivilegedMemoryRegionToken* gets a privileged memory region token value that allows adapter logical addresses to be used directly without memory registration. This token must provide LOCAL_READ and LOCAL_WRITE access. A provider must never allow remote access for the privileged memory region token.

## See also

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)