# IXAPO::Process

## Description

Runs the XAPO's digital signal processing (DSP) code on the given input and output buffers.

## Parameters

### `InputProcessParameterCount` [in]

Number of elements in pInputProcessParameters.

**Note** XAudio2 currently supports only one input stream and one output stream.

### `pInputProcessParameters` [in]

Input array of [XAPO_PROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_process_buffer_parameters) structures.

### `OutputProcessParameterCount` [in]

Number of elements in *pOutputProcessParameters*.

**Note** XAudio2 currently supports only one input stream and one output stream.

### `pOutputProcessParameters` [in, out]

Output array of [XAPO_PROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xapo/ns-xapo-xapo_process_buffer_parameters) structures. On input, the value of **XAPO_PROCESS_BUFFER_PARAMETERS**. **ValidFrameCount** indicates the number of frames that the XAPO should write to the output buffer. On output, the value of **XAPO_PROCESS_BUFFER_PARAMETERS**. **ValidFrameCount** indicates the actual number of frames written.

### `IsEnabled`

TRUE to process normally; FALSE to process thru. See Remarks for additional information.

## Remarks

Implementations of this function should not block, as the function is called from the realtime audio processing thread.

All code that could cause a delay, such as format validation and memory allocation, should be put in the [IXAPO::LockForProcess](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-lockforprocess) method, which is not called from the realtime audio processing thread.

For in-place processing, the *pInputProcessParameters* parameter will not necessarily be the same as *pOutputProcessParameters*. Rather, their *pBuffer* members will point to the same memory.

Multiple input and output buffers may be used with in-place XAPOs, though the input buffer count must equal the output buffer count. For in-place processing when multiple input and output buffers are used, the XAPO may assume the number of input buffers equals the number of output buffers.

In addition to writing to the output buffer, as appropriate, an XAPO is responsible for setting the output stream's buffer flags and valid frame count.

When *IsEnabled* is FALSE, the XAPO should not apply its normal processing to the given input/output buffers during. It should instead pass data from input to output with as little modification possible. Effects that perform format conversion should continue to do so. Effects must ensure transitions between normal and thru processing do not introduce discontinuities into the signal.

When writing a **Process** method, it is important to note XAudio2 audio data is interleaved, which means data from each channel is adjacent for a particular sample number. For example, if there was a 4-channel wave playing into an XAudio2 source voice, the audio data would be a sample of channel 0, a sample of channel 1, a sample of channel 2, a sample of channel 3, and then the next sample of channels 0, 1, 2, 3, and so on.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)