# ADS_PASSWORD_ENCODING_ENUM enumeration

## Description

The **ADS_PASSWORD_ENCODING_ENUM** enumeration identifies the type of password encoding used with the **ADS_OPTION_PASSWORD_METHOD** option in the [IADsObjectOptions::GetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-getoption) and [IADsObjectOptions::SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption) methods.

## Constants

### `ADS_PASSWORD_ENCODE_REQUIRE_SSL:0`

Passwords are encoded using SSL.

### `ADS_PASSWORD_ENCODE_CLEAR:1`

Passwords are not encoded and are transmitted in plaintext.

## See also

[ADS_OPTION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_option_enum)

[IADsObjectOptions::GetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-getoption)

[IADsObjectOptions::SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption)