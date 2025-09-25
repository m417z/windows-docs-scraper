# DHCP_SERVER_OPTIONS structure

## Description

The **DHCP_SERVER_OPTIONS** structure specifies requested DHCP Server options.

## Members

### `MessageType`

DHCP message type.

### `SubnetMask`

Subnet mask.

### `RequestedAddress`

Requested IP address.

### `RequestLeaseTime`

Requested duration of the IP address lease, in seconds.

### `OverlayFields`

Overlay fields to apply to the request.

### `RouterAddress`

IP address of the default gateway.

### `Server`

IP address of the DHCP Server.

### `ParameterRequestList`

List of requested parameters.

### `ParameterRequestListLength`

Length of *ParameterRequestList*, in bytes.

### `MachineName`

Machine name (host name) of the computer making the request.

### `MachineNameLength`

Length of *MachineName*, in bytes.

### `ClientHardwareAddressType`

Type of hardware address expressed in *ClientHardwareAddress*.

### `ClientHardwareAddressLength`

Length of *ClientHardwareAddress*, in bytes.

### `ClientHardwareAddress`

Client hardware address.

### `ClassIdentifier`

Class identifier for the client.

### `ClassIdentifierLength`

Length of *ClassIdentifier*, in bytes.

### `VendorClass`

Vendor class, if applicable.

### `VendorClassLength`

Length of *VendorClass*, in bytes.

### `DNSFlags`

Flags used for DNS.

### `DNSNameLength`

Length of *DNSName*, in bytes.

### `DNSName`

Pointer to the DNS name.

### `DSDomainNameRequested`

Specifies whether the domain name is requested.

### `DSDomainName`

Pointer to the domain name.

### `DSDomainNameLen`

Length of *DSDomainName*, in characters.

### `ScopeId`

Scope identifier for the IP address.