# IWSDiscoveryPublisher::SetAddressFamily

## Description

Specifies the IP address family (IPv4, IPv6, or both) over which the host will be published.

## Parameters

### `dwAddressFamily` [in]

The address family over which the host will be published.

| Value | Meaning |
| --- | --- |
| **WSDAPI_ADDRESSFAMILY_IPV4** | Publish the host over IPv4 addresses. |
| **WSDAPI_ADDRESSFAMILY_IPV6** | Publish the host over IPv6 addresses. |
| **WSDAPI_ADDRESSFAMILY_IPV4 \| WSDAPI_ADDRESSFAMILY_IPV6** | Publish the host over IPv4 and IPv6 addresses. |

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *dwAddressFamily* has a value other than WSDAPI_ADDRESSFAMILY_IPV4, WSDAPI_ADDRESSFAMILY_IPV6, or WSDAPI_ADDRESSFAMILY_IPV4 \| WSDAPI_ADDRESSFAMILY_IPV6. |
| **STG_E_INVALIDFUNCTION** | The address family has already been set for this publisher. |
| **HRESULT_FROM_WIN32(WSAESOCKTNOSUPPORT)** | The system does not support the address family specified by *dwAddressFamily*. |

## Remarks

This method must be called before a notification sink is attached to the publisher.

## See also

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)