# IPhotoAcquireSettings::InitializeFromRegistry

## Description

The `InitializeFromRegistry` method specifies a registry key from which to initialize settings.

## Parameters

### `pszRegistryKey` [in]

Pointer to a null-terminated string containing the registry key.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | This method is not yet implemented. |

## Remarks

The structure of the registry has not yet been determined at this point.

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)