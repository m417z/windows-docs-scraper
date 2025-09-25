# IStylusPlugin::StylusInRange

## Description

Notifies the implementing plug-in that the stylus is entering the detection range of the digitizer.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `tcid` [in]

Tablet context identifier.

### `sid` [in]

Stylus identifier.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The stylus is in range of the digitizer. This is a good place to check if the stylus is inverted and if so, switch to eraser mode.

#### Examples

The following C++ example implements a **IStylusPlugin::StylusInRange Method** method that gets the status of all the buttons on a stylus and reports them to the debug window using the [TRACE](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/4wyz8787(v=vs.100)) macro.

```cpp
STDMETHODIMP CPacketModifier::StylusInRange(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ TABLET_CONTEXT_ID tcid,
            /* [in] */ STYLUS_ID sid)
{
    IInkCursor* pInkCursor;
	HRESULT hr = piRtsSrc->GetStylusForId(sid, &pInkCursor);

	if (SUCCEEDED(hr))
	{
		IInkCursorButtons* pInkCursorButtons;
		hr = pInkCursor->get_Buttons(&pInkCursorButtons);

		if (SUCCEEDED(hr))
		{
			LONG lButtonCount;
			pInkCursorButtons->get_Count(&lButtonCount);

			if (SUCCEEDED(hr))
			{
				IInkCursorButton* pInkCursorButton;
				VARIANT index;
				VariantInit(&index);
				index.vt = VT_I4;

				for (index.intVal = 0; index.intVal < lButtonCount; index.intVal++)
				{
					hr = pInkCursorButtons->Item(index, &pInkCursorButton);

					if (SUCCEEDED(hr))
					{
						InkCursorButtonState currentState;
						hr = pInkCursorButton->get_State(&currentState);

						if (SUCCEEDED(hr))
						{
							switch(currentState)
							{
								case ICBS_Unavailable:
									TRACE("ICBS_Unavailable\n");
									break;

								case ICBS_Up:
									TRACE("ICBS_Up\n");
									break;

								case ICBS_Down:
									TRACE("ICBS_Down\n");
									break;

								default:
									TRACE("Cursor button state unknown.\n");
									break;
							}
						}
					}
				}

				VariantClear(&index);
			}
		}
	}

	return hr;
}

```

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::StylusOutOfRange Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusoutofrange)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)