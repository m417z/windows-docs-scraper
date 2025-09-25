# IMFQualityAdvise::DropTime

## Description

Drops samples over a specified interval of time.

## Parameters

### `hnsAmountToDrop` [in]

Amount of time to drop, in 100-nanosecond units. This value is always absolute. If the method is called multiple times, do not add the times from previous calls.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_DROPTIME_NOT_SUPPORTED** | The object does not support this method. |

## Remarks

Ideally the quality manager can prevent a renderer from falling behind. But if this does occur, then simply lowering quality does not guarantee the renderer will ever catch up. As a result, audio and video might fall out of sync. To correct this problem, the quality manager can call **DropTime** to request that the renderer drop samples quickly over a specified time interval. After that period, the renderer stops dropping samples.

This method is primarily intended for the video renderer. Dropped audio samples cause audio glitching, which is not desirable.

If a component does not support this method, it should return MF_E_DROPTIME_NOT_SUPPORTED.

## See also

[IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise)