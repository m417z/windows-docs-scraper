# ITStream::SelectTerminal

## Description

The
**SelectTerminal** method selects an
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) object onto the stream.

## Parameters

### `pTerminal` [in]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface of selected terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_MAXTERMINALS** | Multiple terminals have been selected on the stream, but media mixing or splitting is not possible. |
| **TAPI_E_INVALIDTERMINAL** | The terminal selected is not valid. |

## Remarks

Terminals can be selected at any time, irrespective of whether the transport is in a state that allows it to stream media. If the transport is in a state that allows it to stream media, and the application has not successfully invoked
[ITStream::PauseStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-pausestream) or
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) on the stream, or has successfully invoked
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) for this stream more recently than it has successfully invoked **ITStream::PauseStream** or **ITStream::StopStream** for this stream, then streaming starts automatically as soon as the terminal is selected. If a terminal is selected on the stream before the transport enters a state in which it can stream media, and no subsequent calls to
**StopStream** or
**PauseStream** are made, then the stream starts automatically when the transport enters a state in which it can stream media.

The CME_STREAM_ACTIVE event is generated when streaming actually starts, which may be later than the
**SelectTerminal** call. The CME_STREAM_FAIL or CME_TERMINAL_FAIL event is generated when streaming actually fails, which may also be later than the
**SelectTerminal** call.

A terminal can be selected onto a stream only if the results of
[ITTerminal::get_MediaType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminal-get_mediatype) match
[ITStream::get_MediaType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-get_mediatype). In addition, some MSPs may require a match between
[ITTerminal::get_Direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminal-get_direction) and
[ITStream::get_Direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-get_direction), although the interface does not enforce this.

Some MSPs may not allow more than a certain number of terminals, typically one, to be simultaneously selected on the same stream, but the interface itself does not enforce any such restriction. Selecting multiple terminals at one time on the same stream is useful, for example, to allow recording of an incoming audio stream to a file while listening to the stream on a pair of speakers.

A given terminal can be selected onto only one stream.

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)