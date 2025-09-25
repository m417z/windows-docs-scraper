# NDK_FN_RELEASE_LAM callback function

## Description

The *NdkReleaseLam* (*NDK_FN_RELEASE_LAM*) function releases an NDK adapter logical address mapping (LAM).

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object
([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `pNdkLAM` [in]

A pointer to an [NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping) structure that was previously initialized by calling the *NdkBuildLAM* ([NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)) function.

## Remarks

*NdkReleaseLam* releases an adapter logical address mapping (LAM). The associated MDL remains unchanged. That is, the MDL is in the same state it hand when it was passed to the *NdkBuildLam* ([NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)) function. The NDK consumer must not release a LAM until after all of the work requests that use the LAM are completed.

## See also

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)

[NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping)