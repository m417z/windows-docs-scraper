# XAPO_REGISTRATION_PROPERTIES structure

## Description

Describes general characteristics of an XAPO. Used with
[IXAPO::GetRegistrationProperties](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-getregistrationproperties), [CXAPOParametersBase::CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapoparametersbase-cxapoparametersbase), and
[CXAPOBase::CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapobase-cxapobase).

## Members

### `clsid`

COM class ID for use with the CoCreateInstance function.

### `FriendlyName`

Friendly name, a unicode string.

### `CopyrightInfo`

Copyright information, a unicode string.

### `MajorVersion`

Major version number.

### `MinorVersion`

Minor version number.

### `Flags`

XAPO property flags that describe the general characteristics of process behavior. These flags are described in the following table.

| Flag | Description |
| --- | --- |
| XAPO_FLAG_INPLACE_SUPPORTED | XAPO supports in-place processing: the input stream buffer and output stream buffer can be the same buffer depending on the input.<br><br>For example, consider an effect which may be ran in stereo to 5.1 mode or mono to mono mode. When set to stereo to 5.1, it will be run with separate input and output buffers as format conversion is not permitted in-place. However, if configured to run mono to mono, the same XAPO can be run in-place. Thus the same implementation may be conveniently reused for various input/output configurations, while taking advantage of in-place processing when possible. |
| XAPO_FLAG_INPLACE_REQUIRED | XAPO requires in-place processing: the input stream buffer and output stream buffer must be the same buffer. When the XAPO_FLAG_INPLACE_REQUIRED is used the XAPO cannot perform format conversions. |
| XAPO_FLAG_CHANNELS_MUST_MATCH | Channel count of the input and output streams must match. |
| XAPO_FLAG_FRAMERATE_MUST_MATCH | Framerate of input and output streams must match. |
| XAPO_FLAG_BITSPERSAMPLE_MUST_MATCH | Bit depth and container size of input and output streams must match. |
| XAPO_FLAG_BUFFERCOUNT_MUST_MATCH | Number of input and output buffers must match, applies to [XAPO_LOCKFORPROCESS_BUFFER_PARAMETERS](https://learn.microsoft.com/windows/win32/api/xapo/ns-xapo-xapo_lockforprocess_parameters). When the XAPO_FLAG_BUFFERCOUNT_MUST_MATCH flag is set **XAPO_REGISTRATION_PROPERTIES**.**MinInputBufferCount** must equal **XAPO_REGISTRATION_PROPERTIES**.**MinOutputBufferCount** and **XAPO_REGISTRATION_PROPERTIES**.**MaxInputBufferCount** must equal **XAPO_REGISTRATION_PROPERTIES**.**MaxOutputBufferCount**. |
| XAPOBASE_DEFAULT_FLAG | XAPO_FLAG_CHANNELS_MUST_MATCH | XAPO_FLAG_FRAMERATE_MUST_MATCH | XAPO_FLAG_BITSPERSAMPLE_MUST_MATCH | XAPO_FLAG_BUFFERCOUNT_MUST_MATCH | XAPO_FLAG_INPLACE_SUPPORTED |

### `MinInputBufferCount`

Minimum number of input streams required for processing.

### `MaxInputBufferCount`

Maximum number of input streams required for processing.

**Note** *MaxInputBufferCount* is currently limited to a value of 1.

### `MinOutputBufferCount`

Minimum number of output streams required for processing.

### `MaxOutputBufferCount`

Maximum number of output streams required for processing.

**Note** *MaxOutputBufferCount* is currently limited to a value of 1.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)