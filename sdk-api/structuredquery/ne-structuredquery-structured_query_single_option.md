# STRUCTURED_QUERY_SINGLE_OPTION enumeration

## Description

A set of flags to be used with [IQueryParser::SetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-setoption) and [IQueryParser::GetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-getoption) to indicate individual options.

## Constants

### `SQSO_SCHEMA:0`

The option value should be a **VT_LPWSTR** that is the path to a file containing a schema binary. It is set automatically when obtaining a query parser through [IQueryParserManager::CreateLoadedParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparsermanager-createloadedparser).

### `SQSO_LOCALE_WORD_BREAKING`

The option value must be **VT_EMPTY** to use the default word breaker (current keyboard locale) or a **VT_UI4** that is a valid LCID. The LCID indicates the expected locale of content words in queries to be parsed and is used to choose a suitable word breaker for the query. [IQueryParser::Parse](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparser-parse) will return an error unless you set either this option or [SQSO_WORD_BREAKER](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_single_option) before calling it.

### `SQSO_WORD_BREAKER`

When setting this option, the value should be a **VT_EMPTY** for using the default word breaker for the chosen locale, or a **VT_UNKNOWN** with an object supporting the [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) interface. Retrieving the option always returns a **VT_UNKNOWN** with an object supporting the **IWordBreaker** interface, unless there is no suitable word breaker for the chosen locale, in which case **VT_EMPTY** is returned.

### `SQSO_NATURAL_SYNTAX`

The option value should be a **VT_EMPTY** or a **VT_BOOL** with **VARIANT_TRUE** to allow both natural query syntax and advanced query syntax (the default) or a **VT_BOOL** with **VARIANT_FALSE** to allow only advanced query syntax. Retrieving the option always returns a **VT_BOOL**.

### `SQSO_AUTOMATIC_WILDCARD`

The option value should be a **VT_BOOL** with **VARIANT_TRUE** to generate query expressions as if each word in the query had the wildcard character * appended to it (unless followed by punctuation other than a parenthesis), a **VT_BOOL** with **VARIANT_FALSE** to use the words as they are (the default), or a **VT_EMPTY**. In most cases, a word-wheeling application should set this option to **VARIANT_TRUE**. Retrieving the option always returns a **VT_BOOL**.

### `SQSO_TRACE_LEVEL`

Reserved. The value should be **VT_EMPTY** (the default) or a **VT_I4**. Retrieving the option always returns a **VT_I4**.

### `SQSO_LANGUAGE_KEYWORDS`

The option value must be a **VT_I4** that is a valid LANGID. The LANGID indicates the expected language of Structured Query keywords in queries to be parsed. It is set automatically when obtaining a query parser through [IQueryParserManager::CreateLoadedParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparsermanager-createloadedparser).

### `SQSO_SYNTAX`

**Windows 7 and later.** The option value must be a **VT_UI4** that is a [SEARCH_QUERY_SYNTAX](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_query_syntax) value. The default is SQS_NATURAL_QUERY_SYNTAX.

### `SQSO_TIME_ZONE`

**Windows 7 and later.** The value must be a **VT_BLOB** that is a copy of a TIME_ZONE_INFORMATION structure. The default is the current time zone.

### `SQSO_IMPLICIT_CONNECTOR`

**Windows 7 and later.** This setting decides what connector should be assumed between conditions when none is specified. The value must be a **VT_UI4** that is a CONDITION_TYPE. Only CT_AND_CONDITION and CT_OR_CONDITION are valid. It defaults to CT_AND_CONDITION.

### `SQSO_CONNECTOR_CASE`

**Windows 7 and later.** This setting decides whether there are special requirements on the case of connector keywords (such as AND or OR). The value must be a **VT_UI4** that is a CASE_REQUIREMENT value. It defaults to CASE_REQUIREMENT_UPPER_IF_AQS.

## Remarks

Windows 7 adds new constants that help refine query condition trees parsed by the [IQueryParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparser) interface.