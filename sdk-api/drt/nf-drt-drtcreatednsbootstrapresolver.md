# DrtCreateDnsBootstrapResolver function

## Description

The **DrtCreateDnsBootstrapResolver** function creates a bootstrap resolver that will use the [GetAddrInfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) system function to resolve the hostname of a will known node already present in the DRT mesh.

## Parameters

### `port` [in]

Specifies the port to which the DRT protocol is bound on the well known node.

### `pwszAddress` [in]

Specifies the hostname of the well known node.

### `ppModule` [out]

Pointer to the [DRT_BOOTSTRAP_PROVIDER](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_bootstrap_provider) module to be included in the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pwszAddress* is **NULL**. |
| **E_OUTOFMEMORY** | The system could not allocate memory for the provider. |

**Note** This function may also return errors from underlying calls to [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) and StringCbPrintfW.

## See also

[DRT_BOOTSTRAP_PROVIDER](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_bootstrap_provider)

[DrtDeleteDnsBootstrapResolver](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeletednsbootstrapresolver)