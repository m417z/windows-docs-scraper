# IWMImageInfo::GetImage

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetImage** method retrieves an image stored in a file as an ID3v2 "APIC" metadata frame.

## Parameters

### `wIndex` [in]

**WORD** containing the image index. This is a number between zero, and one less than the image count retrieved by [IWMImageInfo::GetImageCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmimageinfo-getimagecount).

### `pcchMIMEType` [in, out]

Pointer to a **WORD** containing the length, in wide characters, of *pwszMIMEType*, including the terminating **NULL** character. On the first call to this method, pass **NULL** as *pwszMIMEType* to retrieve the required number of characters.

### `pwszMIMEType` [out]

Pointer to a wide-character **null**-terminated string containing the MIME Type associated with the image. Set to **NULL** on the first call and *pcchMIMEType* will be set to the number of wide characters, including the terminating **NULL**, in this string.

### `pcchDescription` [in, out]

Pointer to a **WORD** containing the length, in wide characters, of *pwszDescription*, including the terminating **NULL** character. On the first call to this method, pass **NULL** as *pwszDescription* to retrieve the required number of characters.

### `pwszDescription` [out]

Pointer to a wide-character **null**-terminated string containing the image description. Set to **NULL** on the first call and *pcchDescription* will be set to the number of wide characters, including the terminating **NULL**, in this string.

### `pImageType` [out]

Pointer to a **WORD** value containing the image type, as defined by the ID3v2 specification. This will be one of the following values.

| Value | Description |
| --- | --- |
| 0 | Picture of a type not specifically listed in this table |
| 1 | 32-pixel-by-32-pixel file icon. Use only with portable network graphics (PNG) format. |
| 2 | File icon not conforming to type 1 above. |
| 3 | Front album cover. |
| 4 | Back album cover. |
| 5 | Leaflet page. |
| 6 | Media. Typically this type of image is of the label side of a CD. |
| 7 | Picture of the lead artist, lead performer, or soloist. |
| 8 | Picture of one of the involved artists or performers. |
| 9 | Picture of the conductor. |
| 10 | Picture of the band or orchestra. |
| 11 | Picture of the composer. |
| 12 | Picture of the lyricist or writer. |
| 13 | Picture of the recording studio or location. |
| 14 | Picture taken during a recording session. |
| 15 | Picture taken during a performance. |
| 16 | Screen capture from a movie or video. |
| 17 | A bright colored fish. |
| 18 | Illustration. |
| 19 | Logo of the band or artist. |
| 20 | Logo of the publisher or studio. |

### `pcbImageData` [in, out]

Pointer to a **DWORD** containing the length, in bytes, of the image pointed to by *pbImageData*. On the first call to this method, pass **NULL** as *pbImageData* to retrieve the required number of bytes.

### `pbImageData` [out]

Pointer to a **BYTE** buffer containing the image data. Set to **NULL** on the first call and *pcbImageData* will be set to the number of bytes in the buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One or more of the following parameters is **NULL**.<br><br>*pcchMIMEType*<br><br>*pcbImageData* |
| **E_UNEXPECTED** | One of the ID3 frames that should be in the file cannot be accessed. |
| **ASF_E_BUFFERTOOSMALL** | The value referenced by one of the following parameters is less than the required buffer size for the corresponding output parameter.<br><br>*pcchMIMEType*<br><br>*pcchDescription*<br><br>*pcbImageData* |

## See also

[GetImageCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmimageinfo-getimagecount)

[IWMImageInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmimageinfo)