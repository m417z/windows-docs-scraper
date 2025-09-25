# IRealTimeStylus::SetSingleTabletMode

## Description

Modifies the mode for [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object to collect input from only one tablet object representing a digitizer attached to the Tablet PC. Stylus input from other digitizers is ignored by the RealTimeStylus.

## Parameters

### `piTablet` [in]

 The [IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object that represents the digitizer device attached to the Tablet PC.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

A [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) can be set to one of two tablet-related modes:

* All tablets mode (default)
* Single tablet mode

If [IRealTimeStylus::SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setalltabletsmode) () was initially called and the RealTimeStylus is enabled, the TPC_E_INVALID_MODE HRESULT is returned.

#### Examples

The following C++ example code sets a [IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus) object, `g_pRealTimeStylus`, to single tablet mode so it can get the tablet and retrieve its plug-and-play identifier. Then it sets the **IRealTimeStylus** object back to all tablets mode.

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

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[RealTimeStylus Reference](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-reference)