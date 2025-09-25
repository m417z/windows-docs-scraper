# IRealTimeStylus::GetTabletContextIdFromTablet

## Description

Retrieves the TabletContextId property that is associated with a given tablet digitizer object.

## Parameters

### `piTablet` [in]

Specifies the tablet object associated with a digitizer for which to get the unique identifier for the tablet context.

### `ptcid` [out, retval]

The unique identifier for the tablet context.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

A digitizer context identifier is specific to an [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object. Two **RealTimeStylus Class** objects may have different context identifiers for the same digitizer object. A tablet context identifier is valid only while a **RealTimeStylus Class** object is enabled. If a **RealTimeStylus Class** object is disabled and then re-enabled, the TCID for each digitizer object might have a different value than it had when the **RealTimeStylus Class** object was first enabled.

This method can be called even if the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is not enabled as long as the **RealTimeStylus Class** has not finished processing data in the queue. This method can be called until the last asynchronous plug-in receives [IStylusPlugin::RealTimeStylusDisabled Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-realtimestylusdisabled).

#### Examples

The following C++ example code gets a pointer to the [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object and uses that to get the tablet context identifier. Then it displays the names of all the tablets attached to the system in the debug output window.

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

[IRealTimeStylus::GetTabletFromTabletContextId Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-gettabletfromtabletcontextid)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)