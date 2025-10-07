# NL\_DAD\_STATE enumeration

The NL\_DAD\_STATE enumeration type defines the duplicate address detection (DAD) state.

## Constants

- **NldsInvalid**
Reserved for system use. Do not use this value in your driver.

- **NldsTentative**
Reserved for system use. Do not use this value in your driver.

- **NldsDuplicate**
Reserved for system use. Do not use this value in your driver.

- **NldsDeprecated**
Reserved for system use. Do not use this value in your driver.

- **NldsPreferred**
Reserved for system use. Do not use this value in your driver.

- **IpDadStateInvalid**
The DAD state is invalid.

- **IpDadStateTentative**
The DAD state is tentative.

- **IpDadStateDuplicate**
A duplicate IP address has been detected.

- **IpDadStateDeprecated**
The IP address has been deprecated.

- **IpDadStatePreferred**
The IP address is the preferred address.

## Remarks

The DAD state applies to both IPv4 and IPv6 addresses.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Nldef.h (include Netioapi.h) |