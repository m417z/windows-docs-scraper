# IRealTimeStylus::GetAllTabletContextIds

## Description

Retrieves an array containing all of the currently active tablet context identifiers.

## Parameters

### `pcTcidCount` [in, out]

The number of tablet context identifiers.

### `ppTcids` [out]

Pointer to the array of tablet context identifiers

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

**IRealTimeStylus::GetAllTabletContextIds Method** method provides access to all the tablet context identifiers that are currently active. This method enables you to get these identifiers directly instead of caching data from [IStylusPlugin::RealTimeStylusEnabled Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-realtimestylusenabled) notifications.

The scope of the TabletContextID property is limited to a given instance of the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class); a Tablet object may have a different unique identifier for each instance of the **RealTimeStylus Class**.

#### Examples

The following C++ example code gets all the tablet context identifiers and uses the first tablet context identifier to get a pointer to the [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object.

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