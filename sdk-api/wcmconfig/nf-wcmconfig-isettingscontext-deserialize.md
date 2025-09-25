# ISettingsContext::Deserialize

## Description

Deserializes the data in the stream that is provided to this context.

## Parameters

### `pStream` [in]

A pointer to an IStream initialized stream object containing the XML representing a settings section of an answer (Unattend.xml) file.
An answers file is a file that facilitates the unattend process during setup or migration to execute all of its tasks automatically, without user intervention.

### `pTarget` [in]

A pointer that identifies [ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo) target object that should be used while deserializing the stream. This target should match the target which will be used on the engine alongside this context.

### `pppResults` [out]

A pointer to an array of [ISettingsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsresult) interface pointers. Each interface pointer identifies an issue which may have occurred during deserialization.

### `pcResultCount` [out]

The number of ISettingsResult objects in the array pppResults.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **WCM_E_NAMESPACENOTFOUND** if pIdentity references a namespace that is not in the context.

This method may return **E_OUTOFMEMORY** if there are insufficient resources on the system to allocate the enumerators.

## See also

[ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext)