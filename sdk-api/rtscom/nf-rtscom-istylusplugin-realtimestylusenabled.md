# IStylusPlugin::RealTimeStylusEnabled

## Description

Notifies the implementing plug-in that the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object is enabled.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `cTcidCount` [in]

Number of tablet context identifiers the RTS has encountered. Valid values are 0 through 8, inclusive.

### `pTcids` [in]

The tablet context identifiers.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is called when the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has been enabled, or when a plug-in is added to a collection.

#### Examples

The following C++ example implements a **IStylusPlugin::RealTimeStylusEnabled Method** method that creates a new instance of an [IStrokeBuilder](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istrokebuilder) object for the purpose of creating Ink strokes from packets collected by a [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

```cpp
STDMETHODIMP CStrokeBuilderPlugin::RealTimeStylusEnabled(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ ULONG cTcidCount,
            /* [size_is][in] */ const TABLET_CONTEXT_ID *pTcids)
{
	// Create an IStrokeBuilder object
	return CoCreateInstance(CLSID_StrokeBuilder, NULL, CLSCTX_INPROC, IID_IStrokeBuilder, (VOID **)&m_pStrokeBuilder);
}

```

## See also

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::RealTimeStylusDisabled Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-realtimestylusdisabled)