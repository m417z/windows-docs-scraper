# IWMPConvert::ConvertFile

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ConvertFile** method is implemented by a conversion plug-in and called by Windows Media Player to enable a conversion plug-in to convert a digital media file into ASF.

## Parameters

### `bstrInputFile` [in]

**BSTR** containing the path to the file to be converted.

### `bstrDestinationFolder` [in]

**BSTR** containing that path to the folder where the converted file must be copied.

### `pbstrOutputFile` [out]

Pointer to a **BSTR** that receives the path to the converted file.

## Return value

The method returns an **HRESULT**. The following table lists recommended return codes.

| Return code/value | Description |
| --- | --- |
| **NS_E_WMP_CONVERT_FILE_FAILED**<br><br>0xC00D1158 | Unspecified failure while converting the file. |
| **NS_E_WMP_CONVERT_NO_RIGHTS_ERRORURL**<br><br>0xC00D1159 | The license prohibits file conversion. **IWMPConvert::GetErrorURL** must return the URL of the webpage that describes the issue. |
| **NS_E_WMP_CONVERT_NO_RIGHTS_NOERRORURL**<br><br>0xC00D115A | The license prohibits file conversion. There is no error URL available. |
| **NS_E_WMP_CONVERT_FILE_CORRUPT**<br><br>0xC00D115B | The specified file is corrupted. |
| **NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_ERRORURL**<br><br>0xC00D115C | There is an unspecified problem with the plug-in. **IWMPConvert::GetErrorURL** must return the URL of the webpage where the user can reinstall the plug-in. |
| **NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_NOERRORURL**<br><br>0xC00D115D | There is an unspecified problem with the plug-in. There is no error URL available. |
| **NS_E_WMP_CONVERT_PLUGIN_UNKNOWN_FILE_OWNER**<br><br>0xC00D115E | This conversion plug-in is not the correct one to convert the current file. |

## Remarks

This is a synchronous call. Your code must complete and return as quickly as possible. This method is not intended to be used for transcoding digital media files. You should use this method only to change the file format.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPConvert Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpconvert)