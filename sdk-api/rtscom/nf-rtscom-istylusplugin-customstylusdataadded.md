# IStylusPlugin::CustomStylusDataAdded

## Description

Notifies the implementing plug-in that custom stylus data is available.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `pGuidId` [in]

The globally unique identifier (GUID) for the custom data.

### `cbData` [in]

The size, in chars, of the buffer, *pbData*. Valid values are 0 through 0x7FFF, inclusive.

### `pbData` [in]

A pointer to the buffer containing the custom data sent by the RTS object.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is called when **IStylusPlugin::CustomStylusDataAdded Method** is being processed. The custom data is passed in the *pbData* member, with a GUID in the *pGuidId* member to pass type information. This class cannot be inherited.

#### Examples

The following C++ code example implements a **IStylusPlugin::CustomStylusDataAdded Method** method that handles the data from a gesture event and sets a static text control, `m_pStatusControl`, to a string representation of the gesture data.

```cpp
STDMETHODIMP CGestureHandler::CustomStylusDataAdded(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const GUID *pGuidId,
            /* [in] */ ULONG cbData,
            /* [in] */ const BYTE *pbData)
{
	// Did we get passed gesture data?
	if (*pGuidId == GUID_GESTURE_DATA)
	{
		// Another way to check for gestures is to see if the data
		// is the right size and actually points to something
		if ((cbData == sizeof(GESTURE_DATA)) && (pbData != NULL))
		{
			// Access the data coming as a GESTURE_DATA structure
			GESTURE_DATA* pGD = (GESTURE_DATA*)pbData;

			CString strStatus;
			CString strGestureId;
			
			// Helper function that maps the gesture ID to a string value
			SetGestureString(pGD->gestureId, &strGestureId);

			strStatus.Format(L"Gesture=%s\tConfidence=%d\tStrokes=%d", strGestureId, pGD->recoConfidence, pGD->strokeCount);
			m_pStatusControl->SetWindowTextW(strStatus);
		}
		else
		{
			m_pStatusControl->SetWindowTextW(L"Not gesture data.");
		}
	}
	else
	{
		m_pStatusControl->SetWindowTextW(L"Not gesture data.");
	}

	return S_OK;
}

```

## See also

[GestureRecognizer Class](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class)

[IGestureRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-igesturerecognizer)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)