# IGamutMapModelPlugIn::Initialize

## Description

Initializes a gamut map model profile (GMMP) by using the specified source and destination gamut boundary descriptions and optional source and destination device model plug-ins.

## Parameters

### `bstrXml` [in]

A string that contains the BSTR XML GMMP profile. This is little-endian Unicode XML, but without the leading bytes to tag it as such. Also, the encoding keyword in the XML may not reflect this format.

### `pSrcPlugIn` [in]

A pointer to a source [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin). If **NULL**, it indicates the source device model profile is not a plug-in profile.

### `pDestPlugIn` [in]

A pointer to a destination [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin). If **NULL**, it indicates the destination device model profile is not a plug-in profile.

### `pSrcGBD` [in]

A pointer to a source [GamutBoundaryDescription](https://learn.microsoft.com/windows/desktop/api/wcsplugin/ns-wcsplugin-gamutboundarydescription).

### `pDestGBD` [in]

A pointer to a destination [GamutBoundaryDescription](https://learn.microsoft.com/windows/desktop/api/wcsplugin/ns-wcsplugin-gamutboundarydescription).

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [IGamutMapModelPlugIn](https://learn.microsoft.com/windows/win32/api/wcsplugin/nn-wcsplugin-igamutmapmodelplugin)