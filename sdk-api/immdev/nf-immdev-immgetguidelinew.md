# ImmGetGuideLineW function

## Description

Retrieves information about errors. Applications use the information for user notifications.

## Parameters

### `unnamedParam1` [in]

Handle to the input context.

### `dwIndex` [in]

Type of guideline information to retrieve. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **GGL_LEVEL** | Return the error level. |
| **GGL_INDEX** | Return the error index. |
| **GGL_STRING** | Return the error message string. |
| **GGL_PRIVATE** | Return information about reverse conversion. |

### `lpBuf` [out, optional]

Pointer to a buffer in which the function retrieves the error message string. This parameter contains **NULL** if *dwIndex* is not GGL_STRING or GGL_PRIVATE or if *dwBufLen* is set to 0.

### `dwBufLen` [in]

Size, in bytes, of the output buffer. The application sets this parameter to 0 if the function is to return the buffer size needed to receive the error message string, not including the terminating null character.

## Return value

Returns an error level, an error index, or the size of an error message string, depending on the value of the *dwIndex* parameter. If *dwIndex* is GGL_LEVEL, the return is one of the following values.

| Value | Meaning |
| --- | --- |
| GL_LEVEL_ERROR | Error. The IME might not be able to continue. |
| GL_LEVEL_FATAL | Fatal error. The IME cannot continue, and data might be lost. |
| GL_LEVEL_INFORMATION | No error. Information is available for the user. |
| GL_LEVEL_NOGUIDELINE | No error. Remove previous error message if still visible. |
| GL_LEVEL_WARNING | Unexpected input or other result. The user should be warned, but the IME can continue. |

If *dwIndex* is GGL_INDEX, the return value is one of the following values.

| Value | Meaning |
| --- | --- |
| GL_ID_CANNOTSAVE | The dictionary or the statistics data cannot be saved. |
| GL_ID_NOCONVERT | The IME cannot convert any more. |
| GL_ID_NODICTIONARY | The IME cannot find the dictionary, or the dictionary has an unexpected format. |
| GL_ID_NOMODULE | The IME cannot find the module that is needed. |
| GL_ID_READINGCONFLICT | A reading conflict occurred. For example, some vowels cannot be put together to form one character. |
| GL_ID_TOOMANYSTROKE | There are too many strokes for one character or one clause. |
| GL_ID_TYPINGERROR | Typing error. The IME cannot handle this typing. |
| GL_ID_UNKNOWN | Unknown error. Refer to the error message string. |
| GL_ID_INPUTREADING | The IME is accepting reading character input from the end user. |
| GL_ID_INPUTRADICAL | The IME is accepting radical character input from the end user. |
| GL_ID_INPUTCODE | The IME is accepting character code input from the end user. |
| GL_ID_CHOOSECANDIDATE | The IME is accepting candidate string selection from the end user. |
| GL_ID_REVERSECONVERSION | Information about reverse conversion is available by calling **ImmGetGuideLine**, specifying GGL_PRIVATE. The information retrieved is in [CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist) format. |

If *dwIndex* is GGL_STRING, the return value is the number of bytes of the string copied to the buffer. However, if *dwBufLen* is 0, the return value is the buffer size needed to receive the string, not including the terminating null character. For Unicode, if *dwBufLen* is 0, the return value is the size, in bytes not including the Unicode terminating null character.

If *dwIndex* is GGL_PRIVATE, the return value is the number of bytes of information copied to the buffer. If *dwIndex* is GGL_PRIVATE and *dwBufLen* is 0, the return value is the buffer size needed to receive the information.

## Remarks

Applications typically call this function after receiving an [IMN_GUIDELINE](https://learn.microsoft.com/windows/desktop/Intl/imn-guideline) command.

> [!NOTE]
> The immdev.h header defines ImmGetGuideLine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist)

[IMN_GUIDELINE](https://learn.microsoft.com/windows/desktop/Intl/imn-guideline)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)