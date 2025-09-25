# IStrokeBuilder::EndStroke

## Description

Ends a stroke and returns the stroke object.

## Parameters

### `tcid` [in]

The tablet context identifier.

### `sid` [in]

The stylus identifier.

### `ppIInkStroke` [in, out]

A pointer to the new stroke. This value can be **NULL**.

### `pDirtyRect` [in, out]

The dirty, or changed, rectangle of the tablet. This value can be **NULL**.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces)..

## Remarks

A dirty region describes a tablet range which has been changed.

#### Examples

The following C++ example shows the implementation of a [IStylusPlugin::StylusUp Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusup) method on an [IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin) object. The plug-in uses a [StrokeBuilder](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class) object to create a new ink stroke. The **IStrokeBuilder::EndStroke Method** method is called from **IStylusPlugin::StylusUp Method** to complete the construction of the stroke and add it to the [Ink](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-get_ink) object of the **StrokeBuilder Class**.

```cpp
STDMETHODIMP CStrokeBuilderPlugin::StylusUp(
            /* [in] */ IRealTimeStylus *piRtsSrc,
            /* [in] */ const StylusInfo *pStylusInfo,
            /* [in] */ ULONG cPropCountPerPkt,
            /* [size_is][in] */ LONG *pPacket,
            /* [out][in] */ LONG **ppInOutPkt)
{
    // Finish the stroke. This adds the stroke to the StrokeBuilder's Ink object.
    return m_pStrokeBuilder->EndStroke(pStylusInfo->tcid, pStylusInfo->cid, &m_piStroke, NULL);
}

```

## See also

[IStrokeBuilder](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istrokebuilder)

[IStrokeBuilder::AppendPackets Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-appendpackets)

[IStrokeBuilder::BeginStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-beginstroke)

[IStrokeBuilder::CreateStroke Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istrokebuilder-createstroke)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)

[StrokeBuilder Class](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class)