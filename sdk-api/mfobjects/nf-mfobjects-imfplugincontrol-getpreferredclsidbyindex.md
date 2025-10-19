# IMFPluginControl::GetPreferredClsidByIndex

## Description

Gets a class identifier (CLSID) from the preferred list, specified by index value.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object to enumerate.

### `index` [in]

The zero-based index of the CLSID to retrieve.

### `selector` [out]

Receives the key name associated with the CLSID. The caller must free the memory for the returned string by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. For more information about the format of key names, see the Remarks section of [IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol).

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