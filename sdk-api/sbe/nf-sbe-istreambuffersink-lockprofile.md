# IStreamBufferSink::LockProfile

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **LockProfile** method locks the Stream Buffer Sink filter's profile, thereby fixing the number of streams and their media types. This method can also specify the name and location of the stub file that points to the backing files.

## Parameters

### `pszStreamBufferFilename` [in]

Pointer to a null-terminated wide-character string that specifies the full path name of the stub file. If the specified file already exists, the method fails. If *pszFilename* is **NULL**, the stub file is created in the current directory with a default file name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The method succeeded. (Multiple calls with the same parameter.) |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | Failure. |
| **VFW_E_UNSUPPORTED_STREAM** | The call failed because there are no streams in the profile. |

## Remarks

The profile describes the number of input streams, their media types, and the location of the stub file that points to the temporary backing files. The profile must be locked before the Stream Buffer Source filter can read data from the backing files. Applications can lock the profile explicitly by calling the **LockProfile** method, or implicitly by running the filter graph that contains the Stream Buffer Sink filter.

After the profile is locked, the Stream Buffer Sink filter does not accept any new pin connections. Pins already connected can be reconnected, but only with the same media type. The profile is unlocked when the graph stops.

The stub file is automatically deleted when the last process closes the file handle. This occurs when the capture graph stops and no render graphs are reading the file.

After the first successful call to this method, further calls with the same value of *pszFileName* return S_FALSE. Further calls with a different value for *pszFileName* fail and return E_UNEXPECTED.

The name of the stub file can be given to the Stream Buffer Source filter through that filter's [IFileSourceFilter::Load](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifilesourcefilter-load) method.

### Windows Vista or later

This method requires administrator privileges, unless you first call [IStreamBufferConfigure3::SetNamespace](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferconfigure3-setnamespace) with the value **NULL**.

## See also

[IStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffersink)