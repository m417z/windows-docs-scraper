# IRealTimeStylus::GetTabletFromTabletContextId

## Description

Retrieves an [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) for a specified tablet context.

## Parameters

### `tcid` [in]

Specifies the unique identifier for the tablet context.

### `ppiTablet` [out, retval]

A pointer to the digitizer object specified by the tablet context identifier.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

A tablet context identifier is specific to a [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object. Two **RealTimeStylus Class** objects can have different context identifiers for the same tablet object. A tablet context identifier is only valid while a **RealTimeStylus Class** object is enabled. If a **RealTimeStylus Class** object is disabled and then re-enabled, the tablet context identifier for each tablet object may have a different value than when the **RealTimeStylus Class** object was first enabled.

This method can be called even if [IRealTimeStylus::Enabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-get_enabled) returns **false** as long as the [IStylusPlugin::RealTimeStylusDisabled Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-realtimestylusdisabled) has not finished processing data in the queue. This method can be called until the last asynchronous plug-in receives **IStylusPlugin::RealTimeStylusDisabled Method**.

#### Examples

The following C++ example code uses the tablet context identifier to get a pointer to the [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object.

```cpp
TABLET_CONTEXT_ID* pTcids = NULL;
TABLET_CONTEXT_ID tcid = 0;
ULONG ulTcidCount = 0;
IInkTablet* pInkTablet = NULL;

if (SUCCEEDED(g_pRealTimeStylus->GetAllTabletContextIds(&ulTcidCount, &pTcids)))
{
    TRACE("Got the tablet context ID array.\n");

    // Loop through all the tablets on the system
    for (ULONG i = 0; i < ulTcidCount; i++)
    {
        // Get the tablet from the context ID
        if (SUCCEEDED(g_pRealTimeStylus->GetTabletFromTabletContextId(pTcids[i], &pInkTablet)))
        {
            // Display the name of the tablet in debug output
            BSTR bstrName;
            if (SUCCEEDED(pInkTablet->get_Name(&bstrName)))
            {
                TRACE("The name of tablet %d is %s.\n", i, bstrName);
            }
        }
    }

    // Get the context ID from the tablet
    if (SUCCEEDED(g_pRealTimeStylus->GetTabletContextIdFromTablet(pInkTablet, &tcid)))
    {
        TRACE("The context ID of the tablet is %d\n", tcid);
    }
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetTabletContextIdFromTablet Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-gettabletcontextidfromtablet)

**RealTimeStylus Class**