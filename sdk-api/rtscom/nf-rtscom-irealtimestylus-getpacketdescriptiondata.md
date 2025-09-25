# IRealTimeStylus::GetPacketDescriptionData

## Description

Retrieves the packet properties and scaling factors.

## Parameters

### `tcid` [in]

Specifies the tablet context identifier.

### `pfInkToDeviceScaleX` [in, out]

Specifies the conversion factor for the horizontal axis from ink space to digitizer coordinates.

### `pfInkToDeviceScaleY` [in, out]

Specifies the conversion factor for the vertical axis from ink space to digitizer coordinates.

### `pcPacketProperties` [in, out]

The number of properties in each packet.

### `ppPacketProperties` [out]

Pointer to an array containing the GUIDs and property metrics for each packet property.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

You can pass **NULL** if you do not want the scaling parameters.

The **IRealTimeStylus::GetPacketDescriptionData Method** uses [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate space for *ppPacketProperties*. The caller should call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when the array is no longer needed.

The order of properties in the stream of data sent to plug-ins is the same as the order of the properties returned by **IRealTimeStylus::GetPacketDescriptionData Method**. Use this method to determine what the hardware is reporting versus what was requested when calling [IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription).

#### Examples

This C++ code example uses the **IRealTimeStylus::GetPacketDescriptionData Method** method to get information about the ink packet data.

```cpp
STDMETHODIMP CCustomRenderer::StylusUp(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPropCountPerPkt,
            /* [size_is][in] */ LONG *pPacket,
            /* [out][in] */ LONG **ppInOutPkt)
{
TABLET_CONTEXT_ID *pTcids;
ULONG ulTcidCount;
TABLET_CONTEXT_ID tcid;
FLOAT fInkToDeviceScaleX;
FLOAT fInkToDeviceScaleY;
ULONG ulPacketProperties;
PACKET_PROPERTY *pPacketProperties;

// Get all the tablet context identifiers
HRESULT hr = piRtsSrc->GetAllTabletContextIds(&ulTcidCount, &pTcids);

// Use the first tablet context identifier in the array
tcid = *pTcids;

// Get the packet description data
hr = piRtsSrc->GetPacketDescriptionData(tcid, &fInkToDeviceScaleX,
                                        &fInkToDeviceScaleY, &ulPacketProperties,
                                        &pPacketProperties);

// Use the packet description data to do things like scale the ink
// to the physical display device when rendering your own strokes

	return S_OK;
}

```

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::GetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getdesiredpacketdescription)

[IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)