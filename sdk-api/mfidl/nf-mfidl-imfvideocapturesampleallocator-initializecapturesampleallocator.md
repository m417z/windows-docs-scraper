## Description

Initializes the sample allocator with parameters relevant to video capture scenarios.

## Parameters

### `cbSampleSize`

A DWORD specifying the sample size in bytes. The actual sample size used by the allocator is the maximum of the size required by pMediaType and cbSampleSize.

### `cbCaptureMetadataSize`

A DWORD specifying the capture metadata size in bytes. Applies only to callers that want to include additional metadata with the captured frames. The metadata size should include the size of a [KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) in addition to the size of the metadata payload itself.

### `cbAlignment`

A DWORD specifying the buffer alignment size in bytes. The default and minimum alignment size is 4KB. Custom alignment sizes less than 4KB will be treated as 4KB.

### `cMinimumSamples`

A DWORD specifying the minimum number of pre-allocated samples. This method will fail if the allocator cannot pre-allocate the specified minimum number of samples.

### `pAttributes`

Optional. An [IMFAttributes](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfattributes) store with additional configuration attributes for the sample allocator. The supported attributes are:

- [MF_SA_BUFFERS_PER_SAMPLE](https://learn.microsoft.com/windows/win32/medfound/mf-sa-buffers-per-sample)
- [MF_SA_D3D11_BINDFLAGS](https://learn.microsoft.com/windows/win32/medfound/mf-sa-d3d11-bindflags)
- [MF_SA_D3D11_USAGE](https://learn.microsoft.com/windows/win32/medfound/mf-sa-d3d11-usage)
- [MF_SA_D3D11_SHARED](https://learn.microsoft.com/windows/win32/medfound/mf-sa-d3d11-shared)
- [MF_SA_D3D11_SHARED_WITHOUT_MUTEX](https://learn.microsoft.com/windows/win32/medfound/mf-sa-d3d11-shared-without-mutex)

### `pMediaType`

An [IMFMediaType](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfmediatype) specifying the media type for which samples will be allocator. The sample allocator uses this parameter to calculate the minimum required size for the media samples.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.
| Return code | Description |
|---------------|---------------|
| S_OK | The method succeeded. |
|MF_E_INVALIDMEDIATYPE | Invalid media type. |

## Remarks

## See also