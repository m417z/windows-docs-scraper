# IStrokeBuilder::AppendPackets

## Description

Adds a packet to the end of the digitizer input packet list.

## Parameters

### `tcid` [in]

The context identifier for the tablet device to which the stylus belongs.

### `sid` [in]

The identifier of the stylus object.

### `cPktBuffLength` [in]

The number of LONGs in the *pPackets* array not the size in bytes. Valid values are between 0 and 0x7FFF, inclusive.

### `pPackets` [in]

The start of the packet data. It is read-only.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method should be called when data packets are sent as a result of the stylus moving while it is touching or in range of the digitizer.

**Note** The incoming packet data is in Himetric format and must be converted to pixels.

#### Examples

The following C++ example shows the implementation of a [IStylusPlugin::Packets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-packets) method on an [IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin) object. The plug-in uses a [StrokeBuilder](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class) object to create a new ink stroke. The **IStrokeBuilder::AppendPackets Method** method is called from **IStylusPlugin::Packets Method** to add new packet data to a stroke in progress as the user drags the stylus across the digitizer.

```cpp
STDMETHODIMP CStrokeBuilderPlugin::Packets(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPktCount,
            /* [in] */ ULONG cPktBuffLength,
            /* [size_is][in] */ LONG *pPackets,
            /* [out][in] */ ULONG *pcInOutPkts,
            /* [out][in] */ LONG **ppInOutPkts)
{
	// Add packet to the stroke
	return m_pStrokeBuilder->AppendPackets(pStylusInfo->tcid, pStylusInfo->cid, cPktBuffLength, pPackets);
}

```

## See also

[CreateStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-createstroke)

[IStrokeBuilder](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istrokebuilder)

[IStrokeBuilder::BeginStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-beginstroke)

[IStrokeBuilder::EndStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-endstroke)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[StrokeBuilder Class](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class)