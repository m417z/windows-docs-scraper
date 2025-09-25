# FAX_RULE_STATUS_ENUM enumeration

## Description

The **FAX_RULE_STATUS_ENUM** enumeration defines the status types for outbound routing rules.

## Constants

### `frsVALID:0`

The routing rule is valid and can be applied to outbound faxes.

### `frsEMPTY_GROUP`

The routing rule cannot be applied because the rule uses an outbound routing group for its destination and the group is empty.

### `frsALL_GROUP_DEV_NOT_VALID`

The routing rule cannot be applied because the rule uses an existing outbound routing group for its destination and the group does not contain devices that are valid for sending faxes.

### `frsSOME_GROUP_DEV_NOT_VALID`

The routing rule uses an existing outbound routing group for its destination but the group contains devices that are not valid for sending faxes.

This is a warning status. The rule can be applied to the valid devices in the routing group.

### `frsBAD_DEVICE`

The routing rule cannot be applied because the rule uses a single device for its destination and that device is not valid for sending faxes.

## See also

[IFaxOutboundRoutingRule::get_Status](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutboundroutingrule-status-vb)