# FWPM_APPC_NETWORK_CAPABILITY_TYPE enumeration

## Description

The **FWPM_APPC_NETWORK_CAPABILITY_TYPE** enumeration specifies the type of app container network capability that is associated with the object or traffic in question.

## Constants

### `FWPM_APPC_NETWORK_CAPABILITY_INTERNET_CLIENT:0`

Allows the app container to make network requests to servers on the Internet. It acts as a client.

### `FWPM_APPC_NETWORK_CAPABILITY_INTERNET_CLIENT_SERVER`

Allows the app container to make requests and to receive requests to and from the Internet. It acts as a client and also as a server.

### `FWPM_APPC_NETWORK_CAPABILITY_INTERNET_PRIVATE_NETWORK`

Allows the app container to make requests and to receive requests to and from private networks (such as a home network, work network, or the corporate domain network of the computer). It acts as a client and also as a server.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)