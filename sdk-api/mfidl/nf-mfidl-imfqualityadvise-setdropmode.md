# IMFQualityAdvise::SetDropMode

## Description

Sets the drop mode. In drop mode, a component drops samples, more or less aggressively depending on the level of the drop mode.

## Parameters

### `eDropMode` [in]

Requested drop mode, specified as a member of the [MF_QUALITY_DROP_MODE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_quality_drop_mode) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_MORE_DROP_MODES** | The component does not support the specified mode or any higher modes. |

## Remarks

If this method is called on a media source, the media source might switch between thinned and non-thinned output. If that occurs, the affected streams will send an [MEStreamThinMode](https://learn.microsoft.com/windows/desktop/medfound/mestreamthinmode) event to indicate the transition. The operation is asynchronous; after **SetDropMode** returns, you might receive samples that were queued before the transition. The MEStreamThinMode event marks the exact point in the stream where the transition occurs.

## See also

[IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise)