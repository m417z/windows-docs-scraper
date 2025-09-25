# IMFASFContentInfo::GetEncodingConfigurationPropertyStore

## Description

Retrieves a property store that can be used to set encoding properties.

## Parameters

### `wStreamNumber` [in]

Stream number to configure. Set to zero to configure file-level encoding properties.

### `ppIStore` [out]

Receives a pointer to the **IPropertyStore** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ASF ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/asf-contentinfo-object)

[IMFASFContentInfo](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfcontentinfo)

[Setting Properties in the ContentInfo Object](https://learn.microsoft.com/windows/desktop/medfound/setting-properties-in-the-contentinfo-object)