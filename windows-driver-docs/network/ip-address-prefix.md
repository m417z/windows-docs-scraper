# IP\_ADDRESS\_PREFIX structure

The IP\_ADDRESS\_PREFIX structure stores an IP address prefix.

## Members

- **Prefix**
The prefix or network part of the address represented as an IP address.

- **PrefixLength**
The length, in bits, of the prefix or network part of the IP address. For a unicast IPv4 address, any value that is greater than 32 is an illegal value. For a unicast IPv6 address, any value that is greater than 128 is an illegal value. A value of 255 is typically used to represent an illegal value.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |