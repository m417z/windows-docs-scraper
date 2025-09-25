# KSPROPERTY_CROSSBAR_ROUTE_S structure

## Description

The KSPROPERTY_CROSSBAR_ROUTE_S structure describes whether a particular routing is possible and specifies the current routing for a pin.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `IndexInputPin`

Specifies the zero-based index of the input pin for which the query is being made.

### `IndexOutputPin`

Specifies the zero-based index of the output pin for which the query is being made.

### `CanRoute`

Returns whether the minidriver supports routing between the pins specified by **IndexInputPin** and **IndexOutputPin**. A nonzero value indicates that routing is supported. If the minidriver does not support routing between the two pins, this value is zero.

## Remarks

If the value of **IndexInputPin** is (-1) on an audio output pin, then the audio stream should be muted.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_CROSSBAR_ROUTE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-crossbar-route)

[PROPSETID_VIDCAP_CROSSBAR](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-crossbar)