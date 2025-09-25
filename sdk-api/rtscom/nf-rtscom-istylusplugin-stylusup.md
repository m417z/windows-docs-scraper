# IStylusPlugin::StylusUp

## Description

Notifies the implementing plug-in that the user has raised the tablet pen from the tablet digitizer surface.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `pStylusInfo` [in]

A [StylusInfo Structure](https://learn.microsoft.com/windows/desktop/api/rtscom/ns-rtscom-stylusinfo) containing the information about the RTS that is associated with the pen.

### `cPropCountPerPkt` [in]

Number of properties per packet. Valid values are 0 through 32, inclusive.

### `pPacket` [in]

The start of the packet data.

### `ppInOutPkt` [in, out]

A pointer to the modified stylus data packet. The plug-in can use this parameter to feed modified packet data to downstream packets. A value other than **NULL** indicates that the packet has been modified and RTS will send this data down to plug-ins by using the *pPacket* parameter.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is used when the pen leaves the digitizer surface.

You can return an array of modified packets in the buffer, *ppInOutPkt*. Packets used by the **IStylusPlugin::StylusUp Method** and [IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown) methods can only be modified. They cannot be deleted. Packets used by the [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets) and [IStylusPlugin::InAirPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-inairpackets) methods can be deleted.

If you modify packets, then *cPropCountPerPkt*, which is the number of LONGs in *ppInOutPkt*, must be divisible by the current desired packet properties (DPP) available on the current input device.

You modify packets by updating the *cPropCountPerPkt* and *ppInOutPkts* parameters. Change *cPropCountPerPkt* to a valid total packet property count and *ppInOutPkts* to a valid data buffer accounting for values for each DPP in every packet. Only one packet can be present at that location for **IStylusPlugin::StylusUp Method** and [IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown).

For example, if you add three packets and your DPP is currently X,Y and Pressure, then you must have nine LONG values in this buffer and set *cPropCountPerPkt* to 9.

The *cPropCountPerPkt* value is useful to help clarify the boundaries between packets in the flat array of integers that comes in for events such as the [NewPackets Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newpackets) event. Packets can be bundled in order to be more efficient with data transfer, such that it is not required that a plug-is called once per packet.

#### Examples

The following C++ code example implements a **StylusUp** method that calls a helper function, **ModifyPacket**, to change the value of the X,Y data to make it fall within a specified rectangle. This is the same functionality that is implemented in the C# sample, [RealTimeStylus Plug-in Sample](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-plug-in-sample). The second code snippet is the **ModifyPacket** function.

```cpp
STDMETHODIMP CPacketModifier::StylusUp(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPropCountPerPkt,
            /* [size_is][in] */ LONG *pPacket,
            /* [out][in] */ LONG **ppInOutPkt)
{
	return ModifyPacket(cPropCountPerPkt, pPacket, ppInOutPkt);
}

```

```cpp
// Helper method to modify a single packet
// Called from StylusDown() and StylusUp()
HRESULT CPacketModifier::ModifyPacket(
            /* [in] */ ULONG cPropCountPerPkt,
            /* [size_is][in] */ LONG *pPacket,
            /* [out][in] */ LONG **ppInOutPkt)
{
	// Pointer to a buffer to hold changed packet values
	LONG* pTempOutPkt = NULL;
	
	// X and Y come first (0 and 1),
	// other properties follow
	ULONG iOtherProps = 2;

	if (cPropCountPerPkt > 0)
	{
		pTempOutPkt = (LONG*)CoTaskMemAlloc(sizeof(LONG)*cPropCountPerPkt);

		if (NULL != pTempOutPkt)
		{
			// Packet data always has x followed by y followed by the rest.
			LONG x = pPacket[0];
			LONG y = pPacket[1];

			// In the packet data, check whether
			// its X,Y values fall outside of the specified rectangle.
			// If so, replace them with the nearest point that still
			// falls within the rectangle.
			x = (x < m_filterRect.left ? m_filterRect.left : x);
			x = (x > m_filterRect.right ? m_filterRect.right : x);
			y = (y < m_filterRect.top ? m_filterRect.top : y);
			y = (y > m_filterRect.bottom ? m_filterRect.bottom : y);

			// If necessary, modify the x,y packet data
			if ((x != pPacket[0]) || (y != pPacket[1]))
			{
				pTempOutPkt[0] = x;
				pTempOutPkt[1] = y;

				// Copy the properties that we haven't modified
				while (iOtherProps < cPropCountPerPkt)
				{
					pTempOutPkt[iOtherProps] = pPacket[iOtherProps++];
				}

				*ppInOutPkt = pTempOutPkt;
			}
			else
			{
				CoTaskMemFree(pTempOutPkt);
			}
		}
	}

	return S_OK;
}

```

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)