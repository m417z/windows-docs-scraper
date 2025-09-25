# IMFPluginControl::IsDisabled

## Description

Queries whether a class identifier (CLSID) appears in the blocked list.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object for the query.

### `clsid` [in]

The CLSID to search for.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The specified CLSID appears in the blocked list. |
| ****E_INVALIDARG**** | Invalid argument. |
| ****HRESULT_FROM_WIN32(ERROR_NOT_FOUND)**** | The specified CLSID is not in the blocked list. |

## See also

[IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol)