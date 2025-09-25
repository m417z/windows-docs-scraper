# IUPnPDevice::IconURL

## Description

The
**IconURL** method returns a URL from which an icon of the specified format can be loaded.

## Parameters

### `bstrEncodingFormat` [in]

Specifies the MIME type of the encoding format that is requested for the icon.

### `lSizeX` [in]

Specifies the width of the icon, in pixels. Standard values are 16, 32, or 48.

### `lSizeY` [in]

Specifies the height of the icon, in pixels. Standard values are 16, 32, or 48 pixels.

### `lBitDepth` [in]

Specifies the bit depth of the icon. Standard values are 8, 16, or 24.

### `pbstrIconURL` [out]

Receives a reference to a string that contains the URL from which the icon is to be loaded. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

An application can specify any values for *lSizeX*, *lSizeY*, and *lBitDepth*. However, there is no guarantee that an icon exists with those specifications.

If a matching icon does not exist, the URL for the icon that most closely matches the size and bit depth specified is returned.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)