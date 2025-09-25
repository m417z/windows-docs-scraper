# IRealTimeStylus::AddStylusAsyncPlugin

## Description

Adds an [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) to the asynchronous plug-in collection at the specified index.

## Parameters

### `iIndex` [in]

Specifies the index of the plug-in in the asynchronous plug-in collection.

### `piPlugin` [in]

The plug-in to add to.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

You cannot add asynchronous plug-ins if [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has a child **RealTimeStylus Class** object.

#### Examples

The following C++ code example adds an instance of an [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) to a [RealTimeStylus](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object. The example code uses the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on a [GestureRecognizer](https://learn.microsoft.com/windows/desktop/tablet/gesturerecognizer-class) plug-in, `g_pGestureHandler`, to get the **IStylusAsyncPlugin** interface, then calls **IRealTimeStylus::AddStylusAsyncPlugin Method**.

```cpp
HRESULT CCOMRTSDlg::InitGestureHandler()
{
	// Create an IGestureHandler object
	HRESULT hr = CoCreateInstance(CLSID_GestureHandler, NULL, CLSCTX_INPROC, IID_IGestureHandler, (VOID **)&g_pGestureHandler);

	if (SUCCEEDED(hr))
	{
		// Get a pointer to the IStylusAsyncPlugin interface
		IStylusAsyncPlugin* pAsyncPlugin;
		hr = g_pGestureHandler->QueryInterface(IID_IStylusAsyncPlugin, reinterpret_cast<void**>(&pAsyncPlugin));
		
		if (SUCCEEDED(hr))
		{
			// Get the current count of plugins so we can
			// add this one to the end of the collection
			ULONG nAsyncPluginCount;
			hr = g_pRealTimeStylus->GetStylusAsyncPluginCount(&nAsyncPluginCount);

			if (SUCCEEDED(hr))
			{
				// Add the plugin to the StylusAsyncPlugin collection
				hr = g_pRealTimeStylus->AddStylusAsyncPlugin(nAsyncPluginCount, pAsyncPlugin);

				if (SUCCEEDED(hr))
				{
					// Pass the Gesture Handler a pointer to the
					// status window so it can update the status
					hr = g_pGestureHandler->SetStatusWindow(&m_staticGestureStatus);
				}
			}
		}
	}
	return hr;
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

**RealTimeStylus Class**