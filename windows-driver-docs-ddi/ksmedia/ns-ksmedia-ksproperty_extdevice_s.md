# KSPROPERTY_EXTDEVICE_S structure

## Description

The KSPROPERTY_EXTDEVICE_S structure describes an external device and its capabilities.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `u`

### `u.Capabilities`

Describes the external device's capabilities.

### `u.DevPort`

Specifies the external device's port. For example:

DEV_PORT_1394

DEV_PORT_USB

### `u.PowerState`

Specifies the external device's power state:

ED_POWER_ON

ED_POWER_STANDBY

ED_POWER_OFF

### `u.pawchString`

Specifies the external device's ID and version.

### `u.NodeUniqueID`

Specifies the external device's unique node Id.

## Remarks

Any ED_Xxx or DEV_PORT_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.

## See also

[DEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagdevcaps)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)