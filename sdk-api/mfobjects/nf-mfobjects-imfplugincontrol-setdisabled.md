# IMFPluginControl::SetDisabled

## Description

Adds a class identifier (CLSID) to the blocked list, or removes a CLSID from the list.

## Parameters

### `pluginType` [in]

Member of the [MF_Plugin_Type](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_plugin_type) enumeration, specifying the type of object.

### `clsid` [in]

The CLSID to add or remove.

### `disabled` [in]

Specifies whether to add or remove the CSLID. If the value is **TRUE**, the method adds the CLSID to the blocked list. Otherwise, the method removes it from the list.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

The blocked list is global to the caller's process. Calling this method does not affect the list in other processes.

## See also

[IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol)