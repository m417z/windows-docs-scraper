# NDK_FN_GET_REMOTE_TOKEN_FROM_MR callback function

## Description

The *NdkGetRemoteTokenFromMr* (*NDK_FN_GET_REMOTE_TOKEN_FROM_MR*) function gets a memory token from a remote NDK memory region (MR).

## Parameters

### `pNdkMr` [in]

A pointer to an NDK memory region (MR) object ([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)).

## Return value

The
*NdkGetRemoteTokenFromMr* function returns a local memory region token.

## Remarks

*NdkGetRemoteTokenFromMr* can be called after an *NdkRegisterMr* ([NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)) or *NdkInitializeFastRegisterMr* ([NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr)) call is completed.

## See also

[NDK_FN_INITIALIZE_FAST_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_initialize_fast_register_mr)

[NDK_FN_REGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_register_mr)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)