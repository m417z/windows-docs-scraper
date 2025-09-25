# IStemmerConfig::SetLocaleInfo

## Description

Sets locale information for the stemmer.

## Parameters

### `dwCodePageID` [in]

ANSI code page number specified at build time.

### `lcid` [in]

Win32 API locale identifier specified at build time.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Locale described by the parameters is supported. |
| **E_INVALIDARG** | Locale described by the parameters is not supported. |

## See also

[IStemmerConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-istemmerconfig)