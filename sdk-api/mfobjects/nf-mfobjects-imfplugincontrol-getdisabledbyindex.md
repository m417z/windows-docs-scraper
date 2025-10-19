# IMFPluginControl::GetDisabledByIndex

## Description

Gets a class identifier (CLSID) from the blocked list.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object to enumerate.

### `index` [in]

The zero-based index of the CLSID to retrieve.

### `clsid` [out]

Receives the CLSID at the specified index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | The *index* parameter is out of range. |

## See also

[IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol)