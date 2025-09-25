# ISpatialAudioMetadataWriter::WriteNextItem

## Description

Starts a new metadata item at the specified offset.

## Parameters

### `frameOffset` [in]

The frame offset of the item within the range specified with the *frameCount* parameter to [ActivateSpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataclient-activatespatialaudiometadataitems).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for writing with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close). |
| **SPTLAUD_MD_CLNT_E_FRAMEOFFSET_OUT_OF_RANGE** | The number of items written in the writing session is greater than the value supplied in the **MaxMetadataItemCount** field in the [SpatialAudioObjectRenderStreamForMetadataActivationParam](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams) passed into [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream). <br><br>The *frameCount* value is greater than the value of the *frameCount* parameter to [ActivateSpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataclient-activatespatialaudiometadataitems) and the overflow mode was set to **SpatialAudioMetadataWriterOverflow_Fail**. |
| **E_INVALIDARG** | The value of *frameOffset* is not greater than the value provided in the previous call to [WriteNextItem](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-writenextitem) within the same writing session. |

## Remarks

Before calling **WriteNextItem**, you must open the [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) for writing by calling [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) after the object is created and after [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close) has been called. During a writing session demarcated by calls to **Open** and **Close**, the value of the *frameOffset* parameter must be greater than the value in the preceding call.

Within a single writing session, you must not use **WriteNextItem** to write more items than the value supplied in the **MaxMetadataItemCount** field in the [SpatialAudioObjectRenderStreamForMetadataActivationParam](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams) passed into [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream) or an SPTLAUD_MD_CLNT_E_FRAMEOFFSET_OUT_OF_RANGE error will occur.

If the overflow mode is set to **SpatialAudioMetadataWriterOverflow_Fail**, the value of the *frameOffset* parameter must be less than he value of the *frameCount* parameter to [ActivateSpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataclient-activatespatialaudiometadataitems) or an SPTLAUD_MD_CLNT_E_FRAMEOFFSET_OUT_OF_RANGE error will occur.

After calling **WriteNextItem**, call [WriteNextItemCommand](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-writenextitemcommand) to write metadata commands and value data for the item.

## See also

[ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter)