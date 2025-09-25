# PEER_PNRP_REGISTRATION_INFO structure

## Description

The **PEER_PNRP_REGISTRATION_INFO** structure contains the information provided by a peer identity when it registers with a PNRP cloud.

## Members

### `pwzCloudName`

Pointer to a Unicode string that contains the name of the PNRP cloud for which this peer identity is requesting registration. If **NULL**, the registration will be made in all clouds. It is possible to use the special value PEER_PNRP_ALL_LINK_CLOUDS to register in all link local clouds.

### `pwzPublishingIdentity`

Pointer to a Unicode string that contains the name of the peer identity requesting registration.

### `cAddresses`

The number of SOCKADDR structures in **ppAddresses**. It is possible to use the special value PEER_PNRP_AUTO_ADDRESSES to have the infrastructure automatically choose addresses.

### `ppAddresses`

Pointer to an array of pointers to SOCKADDR structures that contain the IP addresses bound to the network interface of the peer identity requesting registration.

### `wPort`

The network interface port assigned to the address that the peer is publishing.

### `pwzComment`

Pointer to a zero-terminated Unicode string that contains a comment for this peer endpoint.

### `payload`

A [PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure that contains a pointer to an opaque byte buffer containing application-specific data for the peer endpoint (such as a message or an image).