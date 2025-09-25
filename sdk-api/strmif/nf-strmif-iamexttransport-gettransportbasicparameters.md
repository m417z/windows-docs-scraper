# IAMExtTransport::GetTransportBasicParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTransportBasicParameters` method retrieves general properties of the external transport.

## Parameters

### `Param` [in]

Specifies which property to receive.

### `pValue` [in, out]

Pointer to a variable that receives a **long** integer value. See Remarks for more information.

### `ppszData` [in, out]

Pointer to a variable of type **LPOLESTR** that receives a string. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The *Param* parameter is a flag that specifies which property to retrieve. Some properties are numeric; these are returned in the *pValue* parameter. Other properties are string values; these are returned in the *ppszData* parameter. For a list of flags and expected values, see [IAMExtTransport::SetTransportBasicParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-settransportbasicparameters).

If the method returns a string, the caller must free the string, using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### DV and MPEG Camcorder Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) supports the following additional flags:

* ED_RAW_EXT_DEV_CMD: Invokes a raw AV/C command. Specify the AV/C command as an array of bytes in the *ppszData* parameter. Specify the size of the command, in bytes, in the *pValue* parameter. When the method returns, *ppszData* contains the response from the device, and *pValue* contains the size of the response, in bytes. The AV/C command is passed directly to the device with no validation or error checking.

  The response payload might be larger than the command. It is the caller's responsibility to allocate enough space in the buffer for the response. The maximum payload size is 512 bytes.

  For more information, see [Issuing Raw AV/C Commands](https://learn.microsoft.com/windows/desktop/DirectShow/issuing-raw-av-c-commands).
* ED_TRANSBASIC_INPUT_SIGNAL: Retrieves the signal format that the DV camcorder is designed to accept. Returns one of the following constants in *pValue*.

  | Constant | Description |
  | --- | --- |
  | ED_TRANSBASIC_SIGNAL_525_60_SD | NTSC SD signal. |
  | ED_TRANSBASIC_SIGNAL_525_60_SDL | NTSC SDL (long-play) signal. |
  | ED_TRANSBASIC_SIGNAL_625_50_SD | PAL SD signal. |
  | ED_TRANSBASIC_SIGNAL_625_50_SDL | PAL SDL (long-play) signal. |
  | ED_TRANSBASIC_SIGNAL_MPEG2TS | D-VHS signal. |
* ED_TRANSBASIC_OUTPUT_SIGNAL: Retrieves the signal format that the DV camcorder is designed to transmit. Returns one of the constants listed for the ED_TRANSBASIC_INPUT_SIGNAL flag.

[MSTape](https://learn.microsoft.com/windows/desktop/DirectShow/mstape-driver) supports additional values for ED_TRANSBASIC_INPUT_SIGNAL and ED_TRANSBASIC_OUTPUT_SIGNAL.

| Constant | Description |
| --- | --- |
| ED_TRANSBASIC_SIGNAL_2500_60_MPEG | 25-Mbps/60 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_1250_60_MPEG | 12.5-Mbps/60 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_0625_60_MPEG | 6.25-Mbps/60 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_2500_50_MPEG | 25-Mbps/50 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_1250_50_MPEG | 12.5-Mbps/50 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_0625_50_MPEG | 6.25-Mbps/50 MPEG stream. |
| ED_TRANSBASIC_SIGNAL_UNKNOWN | Unknown signal format. |

These flags are defined in the header file Xprtdefs.h.

In Windows XP Service Pack 2 and later, the following additional signal types are defined for the ED_TRANSBASIC_INPUT_SIGNAL and ED_TRANSBASIC_OUTPUT_SIGNAL flags.

| Constant | Description |
| --- | --- |
| ED_TRANSBASIC_SIGNAL_525_60_DV25 | DVCPRO 25, 525-60. |
| ED_TRANSBASIC_SIGNAL_625_50_DV25 | DVCPRO 25, 625-50. |
| ED_TRANSBASIC_SIGNAL_525_60_DV50 | DVCPRO 50, 525-60. |
| ED_TRANSBASIC_SIGNAL_625_50_DV50 | DVCPRO 50, 625-50. |
| ED_TRANSBASIC_SIGNAL_HD_60_DVH1 | DVCPRO 100, 1080i or 720p |
| ED_TRANSBASIC_SIGNAL_HD_50_DVH1 | DVCPRO 100, 1080i only |

To use these constants, include the header file Xprtdefs.h from the Windows SDK.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)