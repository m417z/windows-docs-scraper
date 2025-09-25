# MFCreateSinkWriterFromURL function

## Description

Creates the sink writer from a URL or byte stream.

## Parameters

### `pwszOutputURL` [in]

A null-terminated string that contains the URL of the output file. This parameter can be **NULL**.

### `pByteStream` [in]

Pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. This parameter can be **NULL**.

If this parameter is a valid pointer, the sink writer writes to the provided byte stream. (The byte stream must be writable.) Otherwise, if *pByteStream* is **NULL**, the sink writer creates a new file named *pwszOutputURL*.

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. You can use this parameter to configure the sink writer. For more information, see [Sink Writer Attributes](https://learn.microsoft.com/windows/desktop/medfound/sink-writer-attributes). This parameter can be **NULL**.

### `ppSinkWriter` [out]

Receives a pointer to the [IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter) interface. The caller must release the interface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_NOT_FOUND** | The specified URL was not found. |

## Remarks

Call **CoInitialize(Ex)** and [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) before calling this function.

The first three parameters to this function can be **NULL**; however, only certain combinations are valid:

| Description | *pwszOutputURL* | *pByteStream* | *pAttributes* |
| --- | --- | --- | --- |
| Specify a byte stream, with no URL. | **NULL** | non-**NULL** | Required (must not be **NULL**). |
| Specify a URL, with no byte stream. | not **NULL** | **NULL** | Optional (may be **NULL**). |
| Specify both a URL and a byte stream. | non-**NULL** | non-**NULL** | Optional (may be **NULL**). |

The *pAttributes* parameter is required in the first case and optional in the others.

* Case 1: Specify a byte stream without a URL. The *pAttributes* parameter must point to an attribute store that contains the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute. The sink writer uses the MF_TRANSCODE_CONTAINERTYPE attribute to determine the type of file container to write, such as ASF or MP4.
* Case 2: Specify a URL without a byte stream. The sink writer creates a new file named *pwszOutputURL*. If *pAttributes* specifies an attribute store with the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute, the sink writer uses that attribute to determine the type of file container. Otherwise, if the MF_TRANSCODE_CONTAINERTYPE attribute is absent or *pAttributes* is **NULL**, the sink writer uses the file name extension to select the container type; for example, ".asf" for an ASF file.
* Case 3: Specify both a URL and a byte stream. The sink writer writes to the byte stream. The URL provided in *pwszOutputURL* is informational only; the sink writer does not create a new file. If *pAttributes* specifies an attribute store with the [MF_TRANSCODE_CONTAINERTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-containertype) attribute, the sink writer uses that attribute to determine the type of file container. Otherwise, the sink writer uses the file name extension to select the container type. The MF_TRANSCODE_CONTAINERTYPE attribute overrides the URL file name extension in this case.

This function is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)