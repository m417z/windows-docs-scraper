# _UCSI_POWER_DIRECTION_ROLE enumeration

## Description

Used in the SET_PDR command. The SET_PDR command is used to set the power direction dictated by the OS Policy Manager (OPM), for the current connection.

## Constants

### `UcsiPowerDirectionRoleProvider:0x1`

The connector initiates swap to source, if not already operating as source.

### `UcsiPowerDirectionRoleConsumer:0x2`

The connector initiates swap to sink, if not already operating as sink.

### `UcsiPowerDirectionRoleAcceptSwap:0x4`

The connector accepts power direction swap requests from the port partner. If this bit is cleared, the connector rejects power direction swap requests from the port partner.

### `UcsiPowerDirectionRoleProviderAcceptSwap:0x5`

This field combines the *UcsiPowerDirectionRoleProvider* and *UcsiPowerDirectionRoleAcceptSwap* values.

### `UcsiPowerDirectionRoleConsumerAcceptSwap:0x6`

This field combines the *UcsiPowerDirectionRoleConsumer* and *UcsiPowerDirectionRoleAcceptSwap* values.

## Remarks

For more information, see section 4.5.10 in the [UCSI spec version 1.2](https://www.intel.com/content/www/us/en/products/docs/io/universal-serial-bus/usb-type-c-ucsi-spec.html).

## See also

- [UCSI spec version 1.2](https://www.intel.com/content/www/us/en/products/docs/io/universal-serial-bus/usb-type-c-ucsi-spec.html)