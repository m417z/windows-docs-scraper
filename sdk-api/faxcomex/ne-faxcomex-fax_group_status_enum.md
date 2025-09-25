# FAX_GROUP_STATUS_ENUM enumeration

## Description

The **FAX_GROUP_STATUS_ENUM** enumeration defines the status types for outbound routing groups.

## Constants

### `fgsALL_DEV_VALID:0`

All the devices in the routing group are valid and available for sending outgoing faxes.

### `fgsEMPTY`

The routing group does not contain any devices.

### `fgsALL_DEV_NOT_VALID`

The routing group does not contain any available devices for sending faxes. (Devices can be "unavailable" when they are offline and when they do not exist.)

### `fgsSOME_DEV_NOT_VALID`

The routing group contains some devices that are unavailable for sending faxes. (Devices can be "unavailable" when they are offline and when they do not exist.)

## See also

[IFaxOutboundRoutingGroup::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutinggroup-status-vb)