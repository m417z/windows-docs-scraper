# IStylusPlugin::InAirPackets

## Description

Notifies the object implementing the plug-in that the stylus is moving above the digitizer.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `pStylusInfo` [in]

A [StylusInfo Structure](https://learn.microsoft.com/windows/desktop/api/rtscom/ns-rtscom-stylusinfo) structure containing the information about the RTS that is associated with the stylus.

### `cPktCount` [in]

The number of properties per data packet.

### `cPktBuffLength` [in]

The length, in **bytes**, of the buffer pointed to by *pPackets*. The memory occupied by each packet is (*cPktBuffLength* / *cPktCount*). Valid values are 0 through 0x7FFF, inclusive.

### `pPackets` [in]

A pointer to the start of the packet data. It is read-only.

### `pcInOutPkts` [in, out]

The number of **LONGs** in *ppInOutPkt*.

### `ppInOutPkts` [in, out]

A pointer to an array of modified stylus data packets. The plug-in can use this parameter to feed modified packet data to downstream packets. For a value other than **NULL**, RTS will send this data down to plug-ins by using the *pPacket* parameter.

## Return value

For a description of return values, see [Classes and Interfaces - Ink Analysis](https://learn.microsoft.com/windows/desktop/tablet/classes-and-interfaces---ink-analysis).

## Remarks

This method is called when data packets are created by the stylus when it is in range but is moving above the digitizer and not touching the digitizer. You can return an array of modified packets by using the *ppInOutPkt* parameter. Create a buffer and point *ppInOutPkts* to it. Only one packet can be present at that location.

**Note** Packets used by the [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets) and **IStylusPlugin::InAirPackets Method** methods can be deleted.

A stylus plug-in may be associated with a single RTS or with many. Use the *piRtsSrc* parameter in the following cases:

* When the notification requires that the plug-in acquires more information about the specific digitizer from which the notification originated.
* When you input additional custom notifications through the system.

Packets can be bundled for more efficient data transfer. Therefore a plug-in is not required to be called once per packet. **IStylusPlugin::InAirPackets Method** and [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets) can send one or more packets.

#### Examples

The following C++ code example implements a [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets) method that modifies the X,Y data to restrain the packets to a rectangle. The same code could be applied to an implementation of **IStylusPlugin::InAirPackets Method**.

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

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown)

[IStylusPlugin::StylusUp Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusup)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)