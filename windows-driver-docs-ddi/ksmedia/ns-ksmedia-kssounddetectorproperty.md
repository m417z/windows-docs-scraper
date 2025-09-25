# KSSOUNDDETECTORPROPERTY structure

## Description

The KSSOUNDDETECTORPROPERTY structure specifies a node and an Event ID. All sound detector property calls into the driver are made using the KSSOUNDDETECTORPROPERTY structure.

## Members

### `Property`

Specifies the property to get or set. This member is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `EventId`

Specifies the event ID GUID.

## Remarks

The EventId is used to identify the different voice assistant/agents such as Cortana. By including the event id with all of the KSPROPERTY_SOUNDDETECTOR_* properties, each agent can be controlled separately, for example like arming "Cortana" without arming "Contoso".

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[Multiple Voice Assistant](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation-mva)