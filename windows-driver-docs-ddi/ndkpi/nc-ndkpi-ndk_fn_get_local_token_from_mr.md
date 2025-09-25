# NDK_FN_GET_LOCAL_TOKEN_FROM_MR callback function

## Description

The *NdkGetLocalTokenFromMr* (*NDK_FN_GET_LOCAL_TOKEN_FROM_MR*) function gets a memory token from a local NDK memory region (MR).

## Parameters

### `pNdkMr` [in]

A pointer to an NDK memory region (MR) object ([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)).

## Return value

The
*NdkGetLocalTokenFromMr* function returns a local memory region token.

## Remarks

*NdkGetLocalTokenFromMr* returns a local memory region token. *NdkGetLocalTokenFromMr* can be called after a call to the *NdkRegisterMr* ([NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)) function or *NdkInitializeFastRegisterMr* ([NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr)) function completes without errors.

## See also

[NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr)

[NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)