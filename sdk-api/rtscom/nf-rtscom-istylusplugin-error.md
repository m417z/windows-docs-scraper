# IStylusPlugin::Error

## Description

Notifies the implementing object that this plug-in or one of the previous plug-ins in either the [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) or [IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin) collection threw an exception.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `piPlugin` [in]

The [IStylusPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin) object that sent the notification.

### `dataInterest` [in]

Identifier of the [IStylusPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin) method that generated the error.

### `hrErrorCode` [in]

The **HRESULT** code for the error that occurred.

### `lptrKey` [in, out]

Used internally by the system.

## Return value

For a description of return values, see [Classes and Interfaces - Ink Analysis](https://learn.microsoft.com/windows/desktop/tablet/classes-and-interfaces---ink-analysis).

## Remarks

This method is called when the RTS object has caught an exception.

#### Examples

The following C++ example implements an **IStylusPlugin::Error Method** method that outputs a message and error code to the debug window using [The TRACE Macro](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/4wyz8787(v=vs.100)).

```cpp
STDMETHODIMP CPacketModifier::Error(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ IStylusPlugin *piPlugin,
            /* [in] */ RealTimeStylusDataInterest dataInterest,
            /* [in] */ HRESULT hrErrorCode,
            /* [out][in] */ LONG_PTR *lptrKey)
{
	CString strError;
	strError.Format(L"An error occurred. Error code: %d", hrErrorCode);
	TRACE(strError);
	return S_OK;
}

```

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::DataInterest Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-datainterest)