# XAUDIO2_DEBUG_CONFIGURATION structure

## Description

Contains the new global debug configuration for XAudio2. Used with the [SetDebugConfiguration](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-setdebugconfiguration) function.

## Members

### `TraceMask`

Bitmask of enabled debug message types. Can be 0 or one or more of the following:

| Value | Description |
| --- | --- |
| XAUDIO2_LOG_ERRORS | Log error messages. |
| XAUDIO2_LOG_WARNINGS | Log warning messages.<br><br>**Note** Enabling XAUDIO2_LOG_WARNINGS also enables XAUDIO2_LOG_ERRORS. |
| XAUDIO2_LOG_INFO | Log informational messages. |
| XAUDIO2_LOG_DETAIL | Log detailed informational messages.<br><br>**Note** Enabling XAUDIO2_LOG_DETAIL also enables XAUDIO2_LOG_INFO. |
| XAUDIO2_LOG_API_CALLS | Log public API function entries and exits. |
| XAUDIO2_LOG_FUNC_CALLS | Log internal function entries and exits.<br><br>**Note** Enabling XAUDIO2_LOG_FUNC_CALLS also enables XAUDIO2_LOG_API_CALLS. |
| XAUDIO2_LOG_TIMING | Log delays detected and other timing data. |
| XAUDIO2_LOG_LOCKS | Log usage of critical sections and mutexes. |
| XAUDIO2_LOG_MEMORY | Log memory heap usage information. |
| XAUDIO2_LOG_STREAMING | Log audio streaming information. |

### `BreakMask`

Message types that will cause an immediate break. Can be 0 or one of the following:

| Value | Description |
| --- | --- |
| XAUDIO2_LOG_ERRORS | Break on error messages. |
| XAUDIO2_LOG_WARNINGS | Break on warning messages.<br><br>**Note** Enabling XAUDIO2_LOG_WARNINGS also enables XAUDIO2_LOG_ERRORS. |

### `LogThreadID`

Indicates whether to log the thread ID with each message.

### `LogFileline`

Indicates whether to log source files and line numbers.

### `LogFunctionName`

Indicates whether to log function names.

### `LogTiming`

Indicates whether to log message timestamps.

## Remarks

Debugging messages can be completely turned off by initializing **XAUDIO2_DEBUG_CONFIGURATION** to all zeroes.

**Note** For this version of XAudio2, only the **XAUDIO2_LOG_ERRORS** value is supported on **TraceMask** or **BreakMask**. All other members and values are ignored.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)