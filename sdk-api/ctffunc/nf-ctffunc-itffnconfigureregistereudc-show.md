# ITfFnConfigureRegisterEudc::Show

## Description

The ITfFnConfigureRegisterEudc::Show method shows the EUDC key sequence register UI.

## Parameters

### `hwndParent` [in]

[in] Handle of the parent window. The text service typically uses this as the parent or owner window when creating a dialog box.

### `langid` [in]

[in] Contains a LANGID value that specifies the identifier of the language.

### `rguidProfile` [in]

[in] Contains a GUID value that specifies the language profile identifier that the text service is under.

### `bstrRegistered`

[in, unique] Contains a BSTR that contains the EUDC to be registered with the text service. This is optional and can be **NULL**. If **NULL**, the text service should display a default register EUDC dialog box.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |