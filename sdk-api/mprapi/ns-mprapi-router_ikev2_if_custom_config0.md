# ROUTER_IKEv2_IF_CUSTOM_CONFIG0 structure

## Description

Gets or sets IKEv2 tunnel configuration parameter for IKEv2 tunnel based demand dial interfaces.

Do not use the **ROUTER_IKEv2_IF_CUSTOM_CONFIG0** structure directly in your code; using [ROUTER_IKEv2_IF_CUSTOM_CONFIG](https://learn.microsoft.com/windows/desktop/RRAS/router-management-data-types) instead ensures that the proper version, based on the operating system the code in compiled under, is used.

## Members

### `dwSaLifeTime`

A value that specifies the lifetime of a security association (SA) after which the SA is no longer valid. This value must be between 300 and 17,279,999 seconds.

### `dwSaDataSize`

A value that specifies the number of kilobytes that are allowed to transfer using a SA. Afterwards, the SA will be renegotiated. This value must be greater than or equal to 1024 KB.

### `certificateName`

A value that specifies the configured certificate that will be sent to the peer for authentication during the main mode SA negotiation for the IKE2 tunnel based VPN connections.

### `customPolicy`

A value that specifies the custom IKEv2 configurations that will be used during the SA negotiation. If set to **NULL**, no custom IKEv2configuration is available.