# NDK_FN_GET_REMOTE_TOKEN_FROM_MW callback function

## Description

The *NdkGetRemoteTokenFromMw* (*NDK_FN_GET_REMOTE_TOKEN_FROM_MW*) function gets a memory token from a remote NDK memory window (MW).

## Parameters

### `pNdkMw` [in]

A pointer to an NDK memory window (MW) object ([NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)).

## Return value

The
*NdkGetRemoteTokenFromMw* function returns a remote memory region token.

## Remarks

 After an *NdkBind* ([NDK_FN_BIND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_bind)) call returns control to the caller, *NdkGetRemoteTokenFromMw* can be called to retrieve the remote token.

## See also

[NDK_FN_BIND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_bind)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)