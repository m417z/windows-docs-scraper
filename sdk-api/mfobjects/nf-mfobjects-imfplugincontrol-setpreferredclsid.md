# IMFPluginControl::SetPreferredClsid

## Description

Adds a class identifier (CLSID) to the preferred list or removes a CLSID from the list.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object.

### `selector` [in]

The key name for the CLSID. For more information about the format of key names, see the Remarks section of [IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol).

### `clsid` [in]

The CLSID to add to the list. If this parameter is **NULL**, the key/value entry specified by the *selector* parameter is removed from the list.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The preferred list is global to the caller's process. Calling this method does not affect the list in other process.

## See also

[IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol)