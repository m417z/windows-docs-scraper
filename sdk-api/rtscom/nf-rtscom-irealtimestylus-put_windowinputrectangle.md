# IRealTimeStylus::put_WindowInputRectangle

## Description

Gets or sets the window input rectangle for the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

This property is read/write.

## Parameters

## Remarks

Each [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object receives tablet pen data for specific section of a window based on the defined window input rectangle for that **RealTimeStylus Class** object.

The default value is an empty window input rectangle, **IRealTimeStylus::WindowInputRectangle Property**, value. When the **IRealTimeStylus::WindowInputRectangle Property** value is empty, {0, 0, 0, 0}, the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object collects pen input over the entire window, even after the window is resized.

After the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object starts collecting pen data, it continues to collect the data until the pen is raised, even if the pen is moved outside of the input region.

Use either an attached [IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin) object or the attached [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) object to uniquely handle pen data that is collected outside of the input region.

The E_INVALIDOPERATION HRESULT is returned when you attempt to set this property on a child [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[RealTimeStylus Reference](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-reference)