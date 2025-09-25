# IUIRibbon::SaveSettingsToStream

## Description

Writes ribbon settings to a binary stream.

## Parameters

### `pStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The stream is handed off to the host application for storage as appropriate.

The **SaveSettingsToStream** method is useful for persisting ribbon state, such as Quick Access Toolbar (QAT) items, across application instances.

## See also

[IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)

[IUIRibbon::LoadSettingsFromStream](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiribbon-loadsettingsfromstream)

[Persisting Ribbon State](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-statepersistence)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)