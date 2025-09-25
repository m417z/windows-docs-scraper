# XAudio2Create function

## Description

Creates a new **XAudio2** object and returns a pointer to its [IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2) interface.

## Parameters

### `ppXAudio2` [out]

If the operation is successful, returns a pointer to an [IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2) object.

### `Flags` [in]

Flags that specify the behavior of the [IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2) object. The value of this parameter must be 0.

### `XAudio2Processor` [in]

An [XAUDIO2_PROCESSOR](https://learn.microsoft.com/windows/desktop/xaudio2/uint32-xaudio2-processor)-typed value that specifies which CPU to use. If multiple bits are specified, the system will create a separate worker thread for each processor.

[XAUDIO2_PROCESSOR](https://learn.microsoft.com/windows/desktop/xaudio2/uint32-xaudio2-processor) default value is XAUDIO2_DEFAULT_PROCESSOR.

**Warning** If you specify [XAUDIO2_ANY_PROCESSOR](https://learn.microsoft.com/windows/desktop/xaudio2/uint32-xaudio2-processor), the system will use all of the device's processors and, as noted above, create a worker thread for each processor.

**Note** Specifying a processor should generally be avoided because it can interfere with the scheduler's ability to schedule threads effectively across processors. Instead, pass the XAUDIO2_DEFAULT_PROCESSOR value (see below).

The special XAUDIO2_DEFAULT_PROCESSOR value causes XAudio2 to use its default processor.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

The DirectX SDK versions of XAUDIO2 supported a flag **XAUDIO2_DEBUG_ENGINE** to select between the release and 'checked' version. This flag is not supported or defined in the Windows 8 version of XAUDIO2.

**Note** No versions of the DirectX SDK contain the xaudio2.lib import library. DirectX SDK versions use COM to create a new **XAudio2** object.

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

**Windows Phone 8.1:** This API is supported.

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[XAudio2 Functions](https://learn.microsoft.com/windows/desktop/xaudio2/functions)