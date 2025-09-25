## Description

Returns the supported combination of configuration options.

## Parameters

### `configuration`

Receives a reference to an [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) object containing the configuration options for the CDM.

## Return value

Returns S_OK on success.

## Remarks

**GetConfiguration** is based on the Encrypted Media Extension specification's [MediaKeySystemAccess.keySystem](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysystemaccess-getconfiguration).

## See also