# UiaGetReservedMixedAttributeValue function

## Description

Retrieves a reserved value indicating that the value of a Microsoft UI Automation text attribute varies within a text range.

## Parameters

### `punkMixedAttributeValue` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives
a reserved value specifying that
an attribute varies over a text range.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)

[Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange)