# acmStreamOpen function

## Description

The **acmStreamOpen** function opens an ACM conversion stream. Conversion streams are used to convert data from one specified audio format to another.

## Parameters

### `phas`

Pointer to a handle that will receive the new stream handle that can be used to perform conversions. This handle is used to identify the stream in calls to other ACM stream conversion functions. If the ACM_STREAMOPENF_QUERY flag is specified, this parameter should be **NULL**.

### `had`

Handle to an ACM driver. If this handle is specified, it identifies a specific driver to be used for a conversion stream. If this parameter is **NULL**, all suitable installed ACM drivers are queried until a match is found.

### `pwfxSrc`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that identifies the desired source format for the conversion.

### `pwfxDst`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that identifies the desired destination format for the conversion.

### `pwfltr`

Pointer to a [WAVEFILTER](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-wavefilter) structure that identifies the desired filtering operation to perform on the conversion stream. If no filtering operation is desired, this parameter can be **NULL**. If a filter is specified, the source (*pwfxSrc*) and destination (*pwfxDst*) formats must be the same.

### `dwCallback`

Pointer to a callback function, a handle of a window, or a handle of an event. A callback function will be called only if the conversion stream is opened with the ACM_STREAMOPENF_ASYNC flag. A callback function is notified when the conversion stream is opened or closed and after each buffer is converted. If the conversion stream is opened without the ACM_STREAMOPENF_ASYNC flag, this parameter should be set to zero.

### `dwInstance`

User-instance data passed to the callback function specified by the *dwCallback* parameter. This parameter is not used with window and event callbacks. If the conversion stream is opened without the ACM_STREAMOPENF_ASYNC flag, this parameter should be set to zero.

### `fdwOpen`

Flags for opening the conversion stream. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_STREAMOPENF_ASYNC |[ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure for the ACMSTREAMHEADER_STATUSF_DONE flag.
| ACM_STREAMOPENF_NONREALTIME | ACM will not consider time constraints when converting the data. By default, the driver will attempt to convert the data in real time. For some formats, specifying this flag might improve the audio quality or other characteristics. |
| ACM_STREAMOPENF_QUERY | ACM will be queried to determine whether it supports the given conversion. A conversion stream will not be opened, and no handle will be returned in the *phas* parameter. |
| CALLBACK_EVENT | The *dwCallback* parameter is a handle of an event. |
| CALLBACK_FUNCTION | The *dwCallback* parameter is a callback procedure address. The function prototype must conform to the [acmStreamConvertCallback](https://learn.microsoft.com/previous-versions/dd742925(v=vs.85)) prototype. |
| CALLBACK_WINDOW | The *dwCallback* parameter is a window handle. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The requested operation cannot be performed. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate resources. |

## Remarks

If an ACM driver cannot perform real-time conversions and the ACM_STREAMOPENF_NONREALTIME flag is not specified for the *fdwOpen* parameter, the open operation will fail returning an ACMERR_NOTPOSSIBLE error code. An application can use the ACM_STREAMOPENF_QUERY flag to determine if real-time conversions are supported for input.

If an application uses a window to receive callback information, the MM_ACM_OPEN, MM_ACM_CLOSE, and MM_ACM_DONE messages are sent to the window procedure function to indicate the progress of the conversion stream. In this case, the [ACMSTREAMHEADER](https://learn.microsoft.com/windows/win32/api/msacm/ns-msacm-acmstreamheader) structure for MM_ACM_DONE, but it is not used for MM_ACM_OPEN and MM_ACM_CLOSE.

If an application uses a function to receive callback information, the MM_ACM_OPEN, MM_ACM_CLOSE, and MM_ACM_DONE messages are sent to the function to indicate the progress of waveform-audio output. The callback function must reside in a dynamic-link library (DLL).

If an application uses an event for callback notification, the event is signaled to indicate the progress of the conversion stream. The event will be signaled when a stream is opened, after each buffer is converted, and when the stream is closed.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)