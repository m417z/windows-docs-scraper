# ISettingsEngine::CreateSettingsContext

## Description

Creates a settings context.

## Parameters

### `Flags` [in]

The value of the Flags parameter may be 0, indicating "normal mode" or 0x00000001, indicating **LIMITED_VALIDATION_MODE**. In normal mode, the settings context validates any changes made to list items against the current state of the target image. For example, if an attempt is made to create a list element that already exists in the image, the create operation fails. In **LIMITED_VALIDATION_MODE**, contradictory data is not accepted. You cannot modify and then add a list item. However, no attempt is made to verify the changes made against the current state of the system. Only use **LIMITED_VALIDATION_MODE** when the intention is to author a context which is to be serialized. Do not specify this flag when creating a context to be used for [ISettingsEngine::ApplySettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsengine-applysettingscontext). If used, the context may not be sufficiently validated and may fail during an application.

### `Reserved` [in]

Reserved. Must be **NULL**.

### `SettingsContext` [out]

A pointer to an [ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext) object that represents the created context.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. This method may return **E_OUTOFMEMORY** if there were insufficient resources to create the [ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext) object.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)