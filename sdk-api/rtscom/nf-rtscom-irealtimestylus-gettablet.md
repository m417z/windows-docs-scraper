# IRealTimeStylus::GetTablet

## Description

Retrieves an [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object to the caller.

## Parameters

### `ppiSingleTablet` [out, retval]

A pointer to the [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method returns, *ppiSingleTablet* will contain **NULL** when the RealTimeStylus is receiving data from more that one tablet. For instance, when the [IRealTimeStylus::SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setalltabletsmode) is called with a value of **TRUE** on a machine with a digitizer and mouse.

#### Examples

The following C++ example code gets a pointer to the [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object and uses that pointer to get the tablet's Plug and Play identifier.

```cpp
// Must be in single tablet mode for GetTablet to succeed. This call to
// SetSingleTabletMode() would likely happen somewhere else in the app.
if (SUCCEEDED(g_pRealTimeStylus->SetSingleTabletMode(pInkTablet)))
{
    IInkTablet* pTablet = NULL;

    if ((SUCCEEDED(g_pRealTimeStylus->GetTablet(&pTablet))) && (NULL != pTablet))
    {
        BSTR bstrPnPID;

        if (SUCCEEDED(pTablet->get_PlugAndPlayId(&bstrPnPID)))
        {
            TRACE("The tablet's Plug-n-Play ID is: %s\n", bstrPnPID);
        }
    }

    // Restore all tablets mode.
    g_pRealTimeStylus->SetAllTabletsMode(TRUE);
}

```

## See also

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

**RealTimeStylus Class**