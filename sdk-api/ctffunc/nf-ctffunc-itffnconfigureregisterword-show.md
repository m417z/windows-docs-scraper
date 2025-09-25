# ITfFnConfigureRegisterWord::Show

## Description

Called to cause the text service to display a dialog box to register a word with the text service.

## Parameters

### `hwndParent` [in]

Handle of the parent window. The text service typically uses this as the parent or owner window when creating the dialog box.

### `langid` [in]

Contains a **LANGID** that specifies the identifier of the language currently used by the Input Method Editor (IME).

### `rguidProfile` [in]

Contains a GUID that specifies the language profile identifier that the text service is under. This is the value specified in [ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile) when the profile was added.

### `bstrRegistered` [in]

Contains a **BSTR** that contains the word to be registered with the text service. This is optional and can be NULL. If NULL, the text service should display a default register word dialog box.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The text service does not implement this method. |

## See also

[ITfFnConfigureRegisterWord](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnconfigureregisterword)

[ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile)