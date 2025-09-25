# IStylusPlugin::DataInterest

## Description

Retrieves the events for which the plug-in is to receive notifications.

## Parameters

### `pDataInterest` [out, retval]

The bitmask indicating the events for which the plug-in is to receive notifications.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The default is **RTSDI_None**.

The [RealTimeStylusDataInterest Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-realtimestylusdatainterest) enumeration bitmask is retrieved every time a plug-in is enabled or disabled. The **DataInterest** mask of a plug-in is queried by the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object when the plug-in has been added to the plug-in collections.

#### Examples

The following C++ example implements a **IStylusPlugin::DataInterest Method** method that sets up a plug-in to receive [IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown), [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets), [IStylusPlugin::StylusUp Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusup), [IStylusPlugin::StylusInRange Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusinrange) and [IStylusPlugin::Error Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-error) notifications.

```cpp
STDMETHODIMP CPacketModifier::DataInterest(
        /* [retval][out] */ RealTimeStylusDataInterest *pDataInterest)
{
	*pDataInterest = (RealTimeStylusDataInterest)(RTSDI_StylusDown | RTSDI_Packets |
												  RTSDI_StylusUp | RTSDI_StylusInRange |
												  RTSDI_Error);
	return S_OK;
}

```

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

[RealTimeStylusDataInterest Enumeration](https://learn.microsoft.com/windows/desktop/api/rtscom/ne-rtscom-realtimestylusdatainterest)