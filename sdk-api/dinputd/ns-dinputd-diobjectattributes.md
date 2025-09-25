# DIOBJECTATTRIBUTES structure

## Description

The DIOBJECTATTRIBUTES structure describes the information contained in the "Attributes" value of the registry key for each "object" on a device. If the "Attributes" value is absent, then default attributes are used.

## Members

### `dwFlags`

 There may be zero, one, or more of the following flags:

#### DIDOI_FFACTUATOR

Indicates that the object can have force feedback effects applied to it.

#### DIDOI_FFEFFECTTRIGGER

Indicates that the object can trigger playback of force feedback effects.

#### DIDOI_ASPECTPOSITION

Indicates that the object reports position information.

#### DIDOI_ASPECTVELOCITY

Indicates that the object reports velocity information.

#### DIDOI_ASPECTACCEL

Indicates that the object reports acceleration information.

#### DIDOI_ASPECTFORCE

Indicates that the object reports force information.

#### DIDOI_ASPECTMASK

Indicates the bits that are used to report aspect information. An object can represent, at most, one aspect.

#### DIDOI_POLLED

Indicates that the object must be explicitly polled in order for data to be retrieved from it. If this flag is not set, then data for the object is interrupt-driven.

### `wUsagePage`

Specifies the HID usage page to associate with the object.

### `wUsage`

Specifies the HID usage to associate with the object.