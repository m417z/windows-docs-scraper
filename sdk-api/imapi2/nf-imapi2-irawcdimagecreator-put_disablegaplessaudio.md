# IRawCDImageCreator::put_DisableGaplessAudio

## Description

Sets the value that specifies if "Gapless Audio" recording is disabled. This property defaults to a value of **VARIANT_FALSE**, which disables the use of "gapless" recording between consecutive audio tracks.

## Parameters

### `value`

A **VARIANT_BOOL** value that specifies if "Gapless Audio" is disabled. Setting a value of **VARIANT_FALSE** disables "Gapless Audio", while **VARIANT_TRUE** enables it.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

When disabled, by default, the audio tracks will have the standard 2-second (150 sector) silent gap between tracks. When enabled, the last 2 seconds of audio data from the previous audio track are encoded in the pregap area of the next audio track, enabling seamless transitions between tracks.

It is recommended that this property value is only set before the process of adding tracks to the image has begun as any changes afterwards could result in adverse effects to other image properties.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::get_DisableGaplessAudio](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-get_disablegaplessaudio)