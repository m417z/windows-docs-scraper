# IUIRibbon::LoadSettingsFromStream

## Description

Reads ribbon settings from a binary stream.

## Parameters

### `pStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_FAIL if the format or content of the serialized stream is empty or cannot be verified by the Ribbon framework.

## Remarks

The stream is supplied by the host application.
If the Windows Ribbon framework is unable to load a valid stream, the default ribbon layout is rendered instead.

The **LoadSettingsFromStream**  method is useful for persisting ribbon state, such as Quick Access Toolbar (QAT) items, across application instances.

## See also

[IUIRibbon](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiribbon)

[IUIRibbon::SaveSettingsToStream](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiribbon-savesettingstostream)

[Persisting Ribbon State](https://learn.microsoft.com/windows/desktop/windowsribbon/ribbon-statepersistence)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)