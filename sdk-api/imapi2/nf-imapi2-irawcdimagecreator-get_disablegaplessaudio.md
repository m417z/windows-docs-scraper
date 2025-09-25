# IRawCDImageCreator::get_DisableGaplessAudio

## Description

Retrieves the current value that specifies if "Gapless Audio" recording is disabled. This property defaults to a value of **VARIANT_FALSE**, which disables the use of "gapless" recording between consecutive audio tracks.

## Parameters

### `value` [out]

A **VARIANT_BOOL** value that specifies if "Gapless Audio" is disabled. A value of **VARIANT_FALSE** indicates that "Gapless Audio" is disabled; **VARIANT_TRUE** indicates that it is enabled.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

When disabled, by default, the audio tracks will have the standard 2-second (150 sector) silent gap between tracks. When enabled, the last 2 seconds of audio data from the previous audio track are encoded in the pregap area of the next audio track, enabling seamless transitions between tracks.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::put_DisableGaplessAudio](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_disablegaplessaudio)