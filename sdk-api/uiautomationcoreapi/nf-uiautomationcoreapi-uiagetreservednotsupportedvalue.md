# UiaGetReservedNotSupportedValue function

## Description

Retrieves a reserved value indicating that a Microsoft UI Automation property or a text attribute is not supported.

## Parameters

### `punkNotSupportedValue` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives the object representing the value.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)

[Text and TextRange Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtextandtextrange)