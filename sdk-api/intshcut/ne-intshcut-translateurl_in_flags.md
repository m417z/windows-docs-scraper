# TRANSLATEURL_IN_FLAGS enumeration

## Description

The **TRANSLATEURL_IN_FLAGS** enumerated values are used with the [TranslateURL](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-translateurla) function to determine how it will execute.

## Constants

### `TRANSLATEURL_FL_GUESS_PROTOCOL:0x0001`

If the protocol scheme is not specified in the *pcszURL* parameter to [TranslateURL](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-translateurla), the system automatically chooses a scheme and adds it to the URL.

### `TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL:0x0002`

If the protocol scheme is not specified in the *pcszURL* parameter to [TranslateURL](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-translateurla), the system adds the default protocol to the URL.