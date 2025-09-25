# IRealTimeStylus::RemoveStylusSyncPlugin

## Description

Removes an [IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin) from the collection at the specified index.

## Parameters

### `iIndex` [in]

The index of the plug-in to be removed.

### `ppiPlugin` [in, out]

A pointer to the plug-in to remove. If you are not interested in receiving the pointer to the removed plug-in, pass **NULL** for this parameter.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Use to dynamically remove a specific plug-in from the synchronous plug-in collection.

The synchronous and asynchronous plug-in collections on [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) can be modified without disabling and then re-enabling **RealTimeStylus Class**.

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

[IRealTimeStylus::RemoveStylusAsyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-removestylusasyncplugin)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)