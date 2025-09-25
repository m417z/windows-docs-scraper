## Description

The **WWAN_ACTIVATION_OPTION** enumeration lists the Packet Data Protocol (PDP) activation options that the MB device supports.

## Constants

### `WwanActivationOptionDefault:0`

All PDU session attributes for activation are provided.

### `WwanActivationOptionPerNonDefaultURSPRules:1`

Use matching non-default URSP rules to activate.

### `WwanActivationOptionPerDefaultURSPRule:2`

Use the default URSP rule to activate.

### `WwanActivationOptionPerURSPRules:3`

Use matching non-default URSPs rules and the default URSP rule to activate.

### `WwanActivationOptionMax:4`

The total number of supported activation options.

## Remarks

## See also