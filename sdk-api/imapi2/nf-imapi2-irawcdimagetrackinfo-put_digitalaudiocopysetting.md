# IRawCDImageTrackInfo::put_DigitalAudioCopySetting

## Description

Sets the digital audio copy "Allowed" bit to one of three values on the resulting media. Please see the [IMAPI_CD_TRACK_DIGITAL_COPY_SETTING](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_track_digital_copy_setting) enumeration for additional information on each possible value.

## Parameters

### `value` [in]

The digital audio copy setting value to assign.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This property may only be set for tracks containing audio data.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IMAPI_CD_TRACK_DIGITAL_COPY_SETTING](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_track_digital_copy_setting)

[IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)