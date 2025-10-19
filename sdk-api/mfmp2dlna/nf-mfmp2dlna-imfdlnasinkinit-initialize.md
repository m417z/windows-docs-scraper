# IMFDLNASinkInit::Initialize

## Description

Initializes the Digital Living Network Alliance (DLNA) media sink.

## Parameters

### `pByteStream` [in]

Pointer to a byte stream. The DLNA media sink writes data to this byte stream. The byte stream must be writable.

### `fPal` [in]

If **TRUE**, the DLNA media sink accepts PAL video formats. Otherwise, it accepts NTSC video formats.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ALREADY_INITIALIZED** | The method was already called. |
| **MF_E_SHUTDOWN** | The media sink's [IMFMediaSink::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method was called. |

## See also

[IMFDLNASinkInit](https://learn.microsoft.com/windows/desktop/api/mfmp2dlna/nn-mfmp2dlna-imfdlnasinkinit)