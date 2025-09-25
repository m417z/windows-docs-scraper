# IStrokeBuilder::CreateStroke

## Description

Creates strokes on an ink object by using packet data that came from a [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

## Parameters

### `cPktBuffLength` [in]

The number of LONGs in the *pPackets* array not the size in bytes. Valid values are between 0 and 0x000FFFFF, inclusive.

### `pPackets` [in]

A pointer to the start of the packet data.

### `cPacketProperties` [in]

The count of longs in the *pPacketProperties* buffer. This is the number of packets multiplied by the number of properties. Valid values are between 0 and 32, inclusive.

### `pPacketProperties` [in]

The buffer containing the packet properties.

### `fInkToDeviceScaleX` [in]

The horizontal, or x-axis, conversion factor for the horizontal axis from ink space to digitizer coordinates.

### `fInkToDeviceScaleY` [in]

The vertical, or y-axis, conversion factor for the vertical axis from ink space to digitizer coordinates.

### `ppIInkStroke` [in, out]

A pointer to the newly created stroke. This value can be **NULL**.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The *fInkToDeviceScaleX* and *fInkToDeviceScaleY* parameters affect the internal representation of strokes created with the **IStrokeBuilder::CreateStroke Method** method. Multiply the x-coordinate in ink space by *fInkToDeviceScaleX* to get the x-coordinate in digitizer units. Multiply the y-coordinate in ink space by *fInkToDeviceScaleY* to get the y-coordinate in digitizer units.

To retrieve the scale parameters, use [IRealTimeStylus::GetPacketDescriptionData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getpacketdescriptiondata).

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IStrokeBuilder](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istrokebuilder)

[IStrokeBuilder::BeginStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-beginstroke)

[IStrokeBuilder::EndStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-endstroke)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[StrokeBuilder Class](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class)