# ID2D1CommandSink::SetUnitMode

## Description

The unit mode changes the meaning of subsequent units from device-independent pixels (DIPs) to pixels or the other way. The command sink does not record a DPI, this is implied by the playback context or other playback interface such as [ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol).

## Parameters

### `unitMode`

Type: **[D2D1_UNIT_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_unit_mode)**

The enumeration that specifies how units are to be interpreted.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The unit mode changes the interpretation of units from DIPs to pixels or vice versa.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::SetTransform](https://learn.microsoft.com/windows/desktop/Direct2D/id2d1rendertarget-settransform)