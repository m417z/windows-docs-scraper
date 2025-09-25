# ITfFnConfigure::Show

## Description

Called when the user opens the Text Services control panel application, selects the text service from the list and presses the Properties pushbutton.

## Parameters

### `hwndParent` [in]

Handle of the parent window. The text service typically uses this as the parent or owner window when creating a dialog box.

### `langid` [in]

Contains a **LANGID** value that specifies the identifier of the language selected in the Text Services control panel application.

### `rguidProfile` [in]

Contains a GUID value that specifies the language profile identifier that the text service is under. This is the value specified in [ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile) when the profile was added.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should not return until the user closes the dialog box or property sheet.

## See also

[ITfFnConfigure](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnconfigure)

[ITfInputProcessorProfiles::AddLanguageProfile](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-addlanguageprofile)