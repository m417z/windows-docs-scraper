# WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V1 structure

## Description

Reserved for system use.
The WHEA_PSHED_PLUGIN_REGISTRATION_PACKET_V1 structure describes the data required for registering a PSHED plug-in with the PSHED.

## Members

### `Length`

### `Version`

The version of the WHEA_PSHED_PLUGIN_REGISTRATION_PACKET structure. V1 PSHED plug-ins must set this member to WHEA_PLUGIN_REGISTRATION_PACKET_V1.

### `Context`

A PSHED plug-in-supplied context area that is passed to the PSHED plug-in's callback functions.

### `FunctionalAreaMask`

A bit-wise OR'ed combination of flags that specifies the functional areas in which the PSHED plug-in participates. Possible flags are:

### `Reserved`

Reserved for system use. PSHED plug-ins should set this member to zero.

### `Callbacks`

A [WHEA_PSHED_PLUGIN_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_callbacks) structure that describes the callback functions for the PSHED plug-in.

## Remarks

V1 plugins do not allow for unregistering. If you try to unregister, a bugcheck may occur.

## See also