# IMFPluginControl::GetPreferredClsid

## Description

Searches the preferred list for a class identifier (CLSID) that matches a specified key name.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object.

### `selector` [in]

The key name to match. For more information about the format of key names, see the Remarks section of [IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol).

### `clsid` [out]

Receives a CLSID from the preferred list.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No CLSID matching this key was found. |

## See also

[IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol)