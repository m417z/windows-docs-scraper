# ITfInputProcessorProfiles::SubstituteKeyboardLayout

## Description

Sets a substitute keyboard layout for the specified language profile.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service of the profile in question.

### `langid` [in]

Contains a **LANGID** value that specifies the language of the profile in question.

### `guidProfile` [in]

Contains a GUID value that identifies the profile in question.

### `hKL` [in]

Contains an **HKL** value that specifies the input locale identifier for the substitute keyboard. Obtain this value by calling [LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)