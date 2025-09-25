# ITfActiveLanguageProfileNotifySink::OnActivated

## Description

Called when the active language or text service changes.

## Parameters

Called when the active language or text service changes.

### `clsid` [in]

CLSID of the TSF text service activated or deactivated. This will be **NULL** for a language change.

### `guidProfile` [in]

Profile GUID for the TSF text service. This is specified by the TSF text service when it is installed. This will be **NULL** for a language change.

### `fActivated` [in]

TRUE if the TSF text service is activated or FALSE if the TSF text service is deactivated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITfActiveLanguageProfileNotifySink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfactivelanguageprofilenotifysink)