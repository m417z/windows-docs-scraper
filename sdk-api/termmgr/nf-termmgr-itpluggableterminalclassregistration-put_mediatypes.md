# ITPluggableTerminalClassRegistration::put_MediaTypes

## Description

The
**put_MediaTypes** method sets the media types supported by the terminal.

## Parameters

### `nMediaTypes` [in]

Bitwise ORed list of the
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) supported by the terminal.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalClassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalclassregistration)

[get_MediaTypes](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalclassregistration-get_mediatypes)