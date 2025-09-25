# IAMVideoCompression::GetInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInfo` method retrieves information about the filter's compression properties, including capabilities and default values.

## Parameters

### `pszVersion` [out]

Pointer to a buffer that receives a version string, such as "Version 2.1.0."

### `pcbVersion` [in, out]

Receives the size of the version string, in bytes.

### `pszDescription` [out]

Pointer to a buffer that receives a description string, such as "My Video Compressor."

### `pcbDescription` [in, out]

Receives the size of the description string, in bytes.

### `pDefaultKeyFrameRate` [out]

Receives the default key-frame rate.

### `pDefaultPFramesPerKey` [out]

Receives the default rate of predicted (P) frames per key frame.

### `pDefaultQuality` [out]

Receives the default quality.

### `pCapabilities` [out]

Receives the compression capabilities, as a bitwise combination of zero or more [CompressionCaps](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-compressioncaps) flags.

## Return value

Returns an **HRESULT** value.

## Remarks

Any of the listed parameters can be **NULL**, in which case the method ignores that parameter.

The application must allocate the buffers for the version and description strings. To determine the required size of the buffers, call this method with **NULL** for the *pszVersion* and *pszDescription* parameters. Use the values returned in *pcbVersion* and *pcbDescription* to allocate the buffers and then call the method again, as shown in the following code:

| C++ |
| --- |
| ``` // Get the size of the version and description strings, in bytes. int cbVersion, cbDesc; hr = pCompress->GetInfo(NULL, &cbVersion, NULL, &cbDesc, NULL, NULL, NULL, NULL); if (SUCCEEDED(hr)) { // Allocate the buffers. WCHAR *pszVersion = new WCHAR[cbVersion / sizeof(WCHAR)]; WCHAR *pszDesc = new WCHAR[cbDesc / sizeof(WCHAR)];<br><br> // Now query for the strings. hr = pCompress->GetInfo(pszVersion, &cbVersion, pszDesc, &cbDesc, NULL, NULL, NULL, NULL); } delete [] pszVersion; delete [] pszDesc; } ``` |

Note that the strings are wide-character strings, and the returned sizes are in bytes, not number of characters. Also, one or both strings might be zero-length.

The *pCapabilities* parameter receives a set of flags indicating which compression properties are supported, and thus which **IAMVideoCompression** methods are supported. For example, if the **CompressionCaps_CanKeyFrame** flag is returned, it the filter supports the [IAMVideoCompression::get_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_keyframerate) and [IAMVideoCompression::put_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_keyframerate) methods.

The remaining parameters receive default values for the compression properties. For unsupported properties (as determined by the flags returned in *pCapabilities*), you should ignore the corresponding default value, as it may not be correct or meaningful.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)