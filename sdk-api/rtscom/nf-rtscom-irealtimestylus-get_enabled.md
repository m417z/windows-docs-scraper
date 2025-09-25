# IRealTimeStylus::get_Enabled

## Description

Gets or sets a value that specifies whether the [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object collects tablet pen data.

This property is read/write.

## Parameters

## Remarks

Multiple [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) objects can exist on the same window provided they are not enabled with overlapping window input rectangles. Enabled **RealTimeStylus** objects on the same window with overlapping input rectangles result in undetermined behavior.

**Note** An overlap can occur without an error if only one of the input rectangles is enabled at any one time.

A child [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object must be connected to be enabled.

Although a [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object can be enabled when it has no plug-ins attached to it, it must have at least one plug-in to be useful.

You receive no events when an object is not enabled.

When the **IRealTimeStylus::Enabled Property** of a container control is set to **false**, all of its contained controls are also disabled.

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::AddCustomStylusDataToQueue Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-addcustomstylusdatatoqueue)

[IRealTimeStylus::GetStyluses Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getstyluses)

[IRealTimeStylus::GetTabletContextIdFromTablet Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-gettabletcontextidfromtablet)

[IRealTimeStylus::GetTabletFromTabletContextId Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-gettabletfromtabletcontextid)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)