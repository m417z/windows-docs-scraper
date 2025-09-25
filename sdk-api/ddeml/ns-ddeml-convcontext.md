# CONVCONTEXT structure

## Description

Contains information supplied by a Dynamic Data Exchange (DDE) client application. The information is useful for specialized or cross-language DDE conversations.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `wFlags`

Type: **UINT**

The conversation context flags. Currently, no flags are defined for this member.

### `wCountryID`

Type: **UINT**

The country/region code identifier for topic-name and item-name strings.

### `iCodePage`

Type: **int**

The code page for topic-name and item-name strings. Non-multilingual clients should set this member to **CP_WINANSI**. Unicode clients should set this value to **CP_WINUNICODE**.

### `dwLangID`

Type: **DWORD**

The [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifier-constants-and-strings) for topic-name and item-name strings.

### `dwSecurity`

Type: **DWORD**

A private (application-defined) security code.

### `qos`

Type: **[SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service)**

The quality of service a DDE client wants from the system during a given conversation. The quality of service level specified lasts for the duration of the conversation. It cannot be changed once the conversation is started.

## Remarks

### Security Warning

For added security, your application can specify a security code with the **dwSecurity** member. The application could then examine this value in the [DdeCallback](https://learn.microsoft.com/windows/desktop/api/ddeml/nc-ddeml-pfncallback) function to check the identity of the client application. However, a value that is hard-coded into an application might be discovered. Thus, you may want to provide the security code in some other way, such as through user input.

## See also

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)