# IStrokeBuilder::BeginStroke

## Description

Begins a stroke on an ink object by using packet data from a [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object.

## Parameters

### `tcid` [in]

The tablet context identifier.

### `sid` [in]

The stylus identifier.

### `pPacket` [in]

The start of the packet data. It is read-only.

### `cPacketProperties` [in]

The count of LONGs, which is the number of packets multiplied by the number of properties, in the *pPacketProperties* buffer.

### `pPacketProperties` [in]

The buffer containing the packet properties.

### `fInkToDeviceScaleX` [in]

The horizontal, or x-axis, conversion factor for the horizontal axis from ink space to digitizer coordinates.

### `fInkToDeviceScaleY` [in]

The vertical, or y-axis, conversion factor for the vertical axis from ink space to digitizer coordinates.

### `ppIInkStroke` [in, out]

A pointer to the new stroke. This value can be **NULL**.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

Used in conjunction with the [IStrokeBuilder::AppendPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-appendpackets) and [IStrokeBuilder::EndStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-endstroke) methods. **IStrokeBuilder::BeginStroke Method** starts building the stroke. As the motion continues and additional packets are received, the **IStrokeBuilder::AppendPackets Method** method adds that additional stroke data. When the tablet pen is raised from the surface and there are no more incoming packets, the **IStrokeBuilder::EndStroke Method** method is called.

#### Examples

The following C++ example shows the implementation of a [IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown) method on an [IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin) object. The plug-in uses a [StrokeBuilder](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class) object to create a new ink stroke. The **IStrokeBuilder::BeginStroke Method** method is called from **IStylusPlugin::StylusDown Method** to initiate the construction of a stroke.

```cpp
STDMETHODIMP CStrokeBuilderPlugin::StylusDown(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPropCountPerPkt,
            /* [size_is][in] */ LONG *pPacket,
            /* [out][in] */ LONG **ppInOutPkt)
{
	FLOAT fInkToDeviceScaleX;
	FLOAT fInkToDeviceScaleY;
	ULONG cPacketProperties;
	PACKET_PROPERTY* pPacketProperties;

	// Get the info we need to call BeginStroke
	HRESULT hr = piRtsSrc->GetPacketDescriptionData(pStylusInfo->tcid, &fInkToDeviceScaleX, &fInkToDeviceScaleY,
													&cPacketProperties, &pPacketProperties);

	if (SUCCEEDED(hr))
	{
		// Start creating the stroke
		hr = m_pStrokeBuilder->BeginStroke(pStylusInfo->tcid, pStylusInfo->cid, pPacket, cPropCountPerPkt,
											pPacketProperties, fInkToDeviceScaleX, fInkToDeviceScaleY, &m_piStroke);
	}
	
	return hr;
}

```

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IStrokeBuilder](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istrokebuilder)

[IStrokeBuilder::AppendPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-appendpackets)

[IStrokeBuilder::CreateStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-createstroke)

[IStrokeBuilder::EndStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-endstroke)

[StrokeBuilder Class](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class)