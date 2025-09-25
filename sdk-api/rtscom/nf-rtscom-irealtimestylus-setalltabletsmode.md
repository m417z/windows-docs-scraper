# IRealTimeStylus::SetAllTabletsMode

## Description

Sets the mode for the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object to collect data from all digitizers.

## Parameters

### `fUseMouseForInput` [in]

**TRUE** for both the mouse and stylus to be used for input; **FALSE** for the mouse not to be used as input.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method enables the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object to collect stylus events from any tablet attached to the Tablet PC. The *fUseMouseForInput* parameter specifies whether the mouse device, as well as the stylus, can be used for input.

If [IRealTimeStylus::SetSingleTabletMode Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setsingletabletmode) () was initially called and [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is enabled, this call is invalid and TPC_E_INVALID_MODE HRESULT is returned.

**Note** The **IRealTimeStylus::SetAllTabletsMode Method** method will fail if the [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) is enabled. On Microsoft Windows XP, this method will return **S_OK** but will have no effect. On Windows Vista, this method will return **E_INVALID_MODE**.

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetTablet Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-gettablet)

[IRealTimeStylus::SetSingleTabletMode Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setsingletabletmode)

**RealTimeStylus Class**