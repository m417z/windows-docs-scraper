# IWMPropertyVault::SetProperty

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProperty** method sets the values for a property. If the property named already exists in the property vault, **SetProperty** changes its value as specified. If the property named does not exist, **SetProperty** adds it to the property vault.

## Parameters

### `pszName` [in]

Pointer to a **null**-terminated string containing the name of the property to set.

The following table lists the property names supported by the **IWMPropertyVault** interface. The property used dictates the data type and meaning of the data pointed to by *pValue*; these values are also in the table. All of these values apply to stream configuration objects.

| Global constant | Data type | Description |
| --- | --- | --- |
| g_wszOriginalSourceFormatTag | **WMT_TYPE_WORD** | When transcoding with smart recompression, set to the **WAVEFORMATEX.wFormatTag** used in the original encoding.This value is now obsolete, use g_wszOriginalWaveFormat instead. |
| g_wszOriginalWaveFormat | **WMT_TYPE_BINARY** | When transcoding with smart recompression, set to the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd757720(v=vs.85)) structure used in the original encoding. |
| g_wszEDL | **WMT_TYPE_STRING** | For Windows Media Audio 9 Voice streams, use to manually specify sections of the stream that contain music. This property should only be used if the automatic selection by the codec is creating a poor quality stream. |
| g_wszComplexity | **WMT_TYPE_WORD** | Set to the complexity setting desired. You can find the complexity levels supported by a codec by calling [IWMCodecInfo3::GetCodecProp](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo3-getcodecprop). |
| g_wszDecoderComplexityRequested | **WMT_TYPE_STRING** | Set to the string value of the device conformance template that you would like the stream to be encoded to. For audio there is only one string value, for video, us the two-letter designation before the ampersand. For more information, see [Device Conformance Template Parameters](https://learn.microsoft.com/windows/desktop/wmformat/device-conformance-template-parameters). |
| g_wszPeakValue | **WMT_TYPE_DWORD** | Set to the peak volume level by the audio codec. Used for normalization. Do not manually set. |
| g_wszAverageLevel | **WMT_TYPE_DWORD** | Set to the average volume level by the audio codec. Used for normalization. Do not manually set. |
| g_wszFold6To2Channels3 | **WMT_TYPE_STRING** | Set to the value for 6 to 2 channel fold down. Use for multichannel audio. |
| g_wszFoldToChannelsTemplate | **WMT_TYPE_STRING** | Template string to create other fold down values. |
| g_wszMusicSpeechClassMode | **WMT_TYPE_STRING** | Set to the type of encoding you want to use with the Windows Media Audio 9 Voice codec. Can be set to:g_wszMusicClassMode<br><br>g_wszSpeechClassMode<br><br>g_wszMixedClassMode |

In addition to the values in the table, the settings for variable bit rate encoding are set using this method. For more information, see [Configuring VBR Streams](https://learn.microsoft.com/windows/desktop/wmformat/configuring-vbr-streams).

### `pType` [in]

Pointer to a member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. This parameter specifies the type of data pointed to by *pValue*.

### `pValue` [in]

Pointer to a data buffer containing the value of the property. This value can be one of several types. The type of data that the buffer contains on output is specified by the value of *pType*.

### `dwSize` [in]

**DWORD** containing the size, in bytes, of the data at *pValue*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pszName* is **NULL** or points to a zero length string.<br><br>OR<br><br>The type specified at *pValue* does not agree with the size in bytes specified by *dwSize*.<br><br>OR<br><br>You are trying to delete a property that does not exist in the property vault. |
| **E_OUTOFMEMORY** | The method cannot allocate memory for a new property.<br><br>OR<br><br>The method cannot allocate memory for a new value. |

## Remarks

Properties set on stream configuration objects using this method are persisted in the profile to which the stream configuration is added. However, files created using that profile do not contain these properties in the header information.

**SetProperty** does not return the index of the property affected. New properties are assigned indexes sequentially.

You can remove a property using **SetProperty** by passing either **NULL** as *pValue* or 0 as *dwSize*.

## See also

[IWMPropertyVault Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpropertyvault)