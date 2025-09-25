# WSD_LOCALIZED_STRING structure

## Description

Represents a single localized string.

## Members

### `lang`

The standard language code used for localization. Valid language codes are specified in [RFC 1766](https://www.ietf.org/rfc/rfc1766.txt).

### `String`

The string data in the localized language.

## Remarks

[RFC 1766](https://www.ietf.org/rfc/rfc1766.txt) extends [ISO-639](https://www.unicode.org/onlinedat/languages.html). Dialect extensions to the [ISO-639](https://www.unicode.org/onlinedat/languages.html) codes are used for the *lang* member. For example, "en-US" is used to indicate a string localized for the USA/English dialect.