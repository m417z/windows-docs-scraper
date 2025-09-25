# IStylusPlugin::Packets

## Description

Notifies the object implementing the plug-in that the tablet pen is moving on the digitizer.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `pStylusInfo` [in]

A [StylusInfo Structure](https://learn.microsoft.com/windows/desktop/api/rtscom/ns-rtscom-stylusinfo) structure which contains information about the RTS that is associated with the pen.

### `cPktCount` [in]

The number of properties per data packet.

### `cPktBuffLength` [in]

The length, in **bytes**, of the buffer pointed to by *pPackets*. The memory occupied by each packet is (*cPktBuffLength* / *cPktCount*). Valid values are 0 through 0x7FFF, inclusive.

### `pPackets` [in]

A pointer to the start of the packet data.

### `pcInOutPkts` [in, out]

The number of **LONGs** in *ppInOutPkt*.

### `ppInOutPkts` [in, out]

A pointer to an array of modified stylus data packets. The plug-in can use this parameter to feed modified packet data to downstream packets. A value other than **NULL** indicates that the RTS will send this data to plug-ins by using the *pPacket* parameter.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Occurs when the pen is moving and is touching the digitizer surface. Use this notification to constrain the packet data within a specified rectangle. Packets used by the **IStylusPlugin::Packets Method** and [IStylusPlugin::InAirPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-inairpackets) methods can be deleted.

You can return an array of modified packets by using the *ppInOutPkt* parameter.

Packets can be bundled in order to make the data transfer more efficient, such that a plug-in is not required to be called once per packet. [IStylusPlugin::InAirPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-inairpackets) and **IStylusPlugin::Packets Method** can send one or more packets.

#### Examples

The following C++ code example implements a **IStylusPlugin::Packets Method** method that modifies the X,Y data to restrain the packets to a rectangle. This is the same functionality that is implemented in C# in the [RealTimeStylus Plug-in Sample](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-plug-in-sample).

```cpp
STDMETHODIMP CPacketModifier::Packets(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPktCount,
            /* [in] */ ULONG cPktBuffLength,
            /* [size_is][in] */ LONG *pPackets,
            /* [out][in] */ ULONG *pcInOutPkts,
            /* [out][in] */ LONG **ppInOutPkts)
{
	BOOL fModified = FALSE;                             // Did we change the packet data?
	ULONG cPropertyCount = cPktBuffLength/cPktCount;    // # of properties in a packet
	ULONG iOtherProps = 0;                              // Properties other than X and Y

	// Allocate memory for modified packets
	LONG* pTempOutPkts = (LONG*)CoTaskMemAlloc(sizeof(ULONG)*cPktBuffLength);

	// For each packet in the packet data, check whether
	// its X,Y values fall outside of the specified rectangle.
	// If so, replace them with the nearest point that still
	// falls within the rectangle.
	for (ULONG i = 0; i < cPktCount; i += cPropertyCount)
	{
		// Packet data always has X followed by Y
		// followed by the rest
		LONG x = pPackets[i];
		LONG y = pPackets[i+1];

		// Constrain points to the input rectangle
		x = (x < m_filterRect.left ? m_filterRect.left : x);
		x = (x > m_filterRect.right ? m_filterRect.right : x);
		y = (y < m_filterRect.top ? m_filterRect.top : y);
		y = (y > m_filterRect.bottom ? m_filterRect.bottom : y);

		// If necessary, modify the X,Y packet data
		if ((x != pPackets[i]) || (y != pPackets[i+1]))
		{
			pTempOutPkts[i] = x;
			pTempOutPkts[i+1] = y;
			iOtherProps = i+2;
		
			// Copy the properties that we haven't modified
			while (iOtherProps < (i + cPropertyCount))
			{
				pTempOutPkts[iOtherProps] = pPackets[iOtherProps++];
			}

			fModified = TRUE;
		}
	}

	if (fModified)
	{
		// Set the [out] pointer to the
		// memory we allocated and updated
		*ppInOutPkts = pTempOutPkts;
		*pcInOutPkts = cPktCount;
	}
	else
	{
		// Nothing modified, release the memory we allocated
		CoTaskMemFree(pTempOutPkts);
	}

	return S_OK;
}

```

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

**IStylusPlugin Interface**

[IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown)

[IStylusPlugin::StylusUp Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusup)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)