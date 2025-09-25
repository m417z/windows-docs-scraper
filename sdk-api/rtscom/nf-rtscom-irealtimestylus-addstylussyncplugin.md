# IRealTimeStylus::AddStylusSyncPlugin

## Description

Adds an [IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin) to the synchronous plug-in collection at the specified index.

## Parameters

### `iIndex` [in]

The index of the synchronous plug-in collection where the plug-in is added.

### `piPlugin` [in]

The plug-in that is added.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Use this to dynamically add a plug-in to the synchronous plug-in collection.

The synchronous and asynchronous plug-in collections on the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object can be modified without disabling and then re-enabling the **RealTimeStylus Class** object.

Plugins must aggregate the free threaded marshaler and must not be single threaded apartment objects.

#### Examples

The following C++ code example implements an event handler for a **CheckBox Control (Windows Forms)**. Depending on the checked state of the control, represented by the `m_btnPacketFilter` member variable, the function either adds or removes the plug-in represented by the global `g_pPacketModifier` variable.

```cpp
void CCOMRTSDlg::OnBnClickedCheckPacketFilter()
{
	HRESULT hr;
	IStylusSyncPlugin* pSyncPlugin;

	hr = g_pPacketModifier->QueryInterface(IID_IStylusSyncPlugin, reinterpret_cast<void**>(&pSyncPlugin));

	if (SUCCEEDED(hr))
	{
		if (m_btnPacketFilter.GetCheck())
		{
			// If the checkbox is checked, add the
			// Packet Modifier plugin to the RealTimeStylus
			hr = g_pRealTimeStylus->AddStylusSyncPlugin(0, pSyncPlugin);
		}
		else
		{
			// If the checkbox is not checked, remove the
			// Packet Modifier plugin from the RealTimeStylus
			hr = g_pRealTimeStylus->RemoveStylusSyncPlugin(0, &pSyncPlugin);
		}
	}
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::AddStylusAsyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-addstylusasyncplugin)

**RealTimeStylus Class**