# ITfInputProcessorProfileSubstituteLayout::GetSubstituteKeyboardLayout

## Description

Retrieves the input locale identifier (keyboard layout).

## Parameters

### `rclsid` [in]

Contains the class identifier of the text service.

### `langid` [in]

Specifies the language of the profile. See [Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers).

### `guidProfile` [in]

Identifies the profile GUID.

### `phKL` [out]

Pointer to an **HKL** value that specifies the substitute input locale identifier.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfInputProcessorProfileSubstituteLayout](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofilesubstitutelayout)

[Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers)

[LoadKeyboardLayout](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadkeyboardlayouta)

[Text Service Registration](https://learn.microsoft.com/windows/desktop/TSF/text-service-registration)