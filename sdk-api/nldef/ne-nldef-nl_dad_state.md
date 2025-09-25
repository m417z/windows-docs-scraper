# NL_DAD_STATE enumeration

## Description

The **IP_DAD_STATE** enumeration specifies information about the duplicate address detection (DAD) state for an IPv4 or IPv6 address.

## Constants

### `NldsInvalid`

### `NldsTentative`

### `NldsDuplicate`

### `NldsDeprecated`

### `NldsPreferred`

### `IpDadStateInvalid:0`

The DAD state is invalid.

### `IpDadStateTentative`

The DAD state is tentative.

### `IpDadStateDuplicate`

A duplicate IP address has been detected.

### `IpDadStateDeprecated`

The IP address has been deprecated.

### `IpDadStatePreferred`

The IP address is the preferred address.

## Remarks

The **IP_DAD_STATE** enumeration is used in the **DadState** member of the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **IP_DAD_STATE** enumeration is defined in the *Nldef.h* header file which is automatically included by the *Iptypes.h* header file. The *Nldef.h* and *Iptypes.h* header files should never be used directly.

## See also

[IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh)