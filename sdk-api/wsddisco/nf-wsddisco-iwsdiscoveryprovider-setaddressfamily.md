# IWSDiscoveryProvider::SetAddressFamily

## Description

Specifies the IP address family (IPv4, IPv6, or both) to search when discovering WSD devices.

## Parameters

### `dwAddressFamily` [in]

The address family to search when discovering devices.

| Value | Meaning |
| --- | --- |
| **WSDAPI_ADDRESSFAMILY_IPV4** | Search over IPv4 addresses. |
| **WSDAPI_ADDRESSFAMILY_IPV6** | Search over IPv6 addresses. |
| **WSDAPI_ADDRESSFAMILY_IPV4 | WSDAPI_ADDRESSFAMILY_IPV6** | Search over IPv4 and IPv6 addresses. |

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *dwAddressFamily* has a value other than WSDAPI_ADDRESSFAMILY_IPV4, WSDAPI_ADDRESSFAMILY_IPV6, or WSDAPI_ADDRESSFAMILY_IPV4 | WSDAPI_ADDRESSFAMILY_IPV6. |
| **STG_E_INVALIDFUNCTION** | The address family has already been set for this publisher. |
| **HRESULT_FROM_WIN32(WSAESOCKTNOSUPPORT)** | The system does not support the address family specified by *dwAddressFamily*. |

## Remarks

This method can be called only once on a provider. This method must be called before a notification sink is attached to the provider. That means **SetAddressFamily** must be called before [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) is called on a provider.

## See also

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)