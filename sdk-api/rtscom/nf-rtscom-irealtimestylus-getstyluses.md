# IRealTimeStylus::GetStyluses

## Description

Retrieves the collection of styluses the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has encountered.

## Parameters

### `ppiInkCursors` [out, retval]

When this method returns, contains a pointer to the collection of styluses the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has encountered.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) collection includes the styluses for which a tablet context has been created. The collection does not include all styluses available in the system in the stylus collection.

If no stylus object has been detected on the tablet objects associated with the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object, this method returns an empty array.

This method cannot be called unless it the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is connected and enabled **RealTimeStylus Class**.

**Note** This method can be called if [IRealTimeStylus::Enabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-get_enabled) returns false as long as the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has not finished processing data in the queue. This method can be called until the last asynchronous plug-in receives [IStylusPlugin::RealTimeStylusDisabled Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-realtimestylusdisabled).

#### Examples

The following C++ example code gets an array of the Stylus objects that the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has encountered since it was last enabled. It then iterates through the array reporting the ID of each stylus in debug output.

```cpp
IInkCursors *piInkCursors;

if (SUCCEEDED(g_pRealTimeStylus->GetStyluses(&piInkCursors)))
{
    long lCursorCount;

    if (SUCCEEDED(piInkCursors->get_Count(&lCursorCount)))
    {
        for (long l = 0; l < lCursorCount; l++)
        {
            LONG sid;
            IInkCursor *piInkCursor;
            IInkCursor *piInkCursorForId;

            piInkCursors->Item(l, &piInkCursor);
            piInkCursor->get_Id(&sid);

            if (SUCCEEDED(g_pRealTimeStylus->GetStylusForId((STYLUS_ID)sid, &piInkCursorForId)))
            {
                TRACE("Got stylus with ID %d\n", sid);
            }
        }
    }
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetStylusForId Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getstylusforid)

**RealTimeStylus Class**