# IMbnMultiCarrierEvents::OnSetHomeProviderComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider) operation.

## Parameters

### `mbnInterface` [in]

An [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object that represents the Mobile Broadband device [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider) operation.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to the [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider) operation.

### `status` [in]

A status code that indicates the outcome of [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider).

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_MBN_PROVIDER_NOT_VISIBLE** | The requested provider is not visible. |
| **E_INVALIDARG** | Invalid registration mode input, the provider ID provided as input is longer than the maximum length 7 characters, or data class provided is invalid. The Mobile Broadband service will not send the request to the device when invalid arguments are provided in the input. In manual registration mode, this indicates that the requested provider is forbidden. |
| **E_FAIL** | The operation could not be completed. More information is available in the network error code. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## Return value

This method must return **S_OK**.

## Remarks

If *status* is **S_OK**, the home provider for the interface has been successfully set to the new provider by [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider). Otherwise, the original home provider is not changed and the previous states, such as connection, packet service etc, of the interface remain unchanged.

## See also

[IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents)