# QUERY_PARSER_MANAGER_OPTION enumeration

## Description

Used by [IQueryParserManager::SetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparsermanager-setoption) to set parsing options. This can be used to specify schemas and localization options.

## Constants

### `QPMO_SCHEMA_BINARY_NAME:0`

A **VT_LPWSTR** containing the name of the file that contains the schema binary. The default value is **StructuredQuerySchema.bin** for the SystemIndex catalog and **StructuredQuerySchemaTrivial.bin** for the trivial catalog.

### `QPMO_PRELOCALIZED_SCHEMA_BINARY_PATH`

Either a **VT_BOOL** or a **VT_LPWSTR**. If the value is a **VT_BOOL** and is **FALSE**, a pre-localized schema will not be used. If the value is a **VT_BOOL** and is **TRUE**, [IQueryParserManager](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparsermanager) will use the pre-localized schema binary in "`%ALLUSERSPROFILE%\Microsoft\Windows`". If the value is a **VT_LPWSTR**, the value should contain the full path of the folder in which the pre-localized schema binary can be found. The default value is **VT_BOOL** with **TRUE**.

### `QPMO_UNLOCALIZED_SCHEMA_BINARY_PATH`

A **VT_LPWSTR** containing the full path to the folder that contains the unlocalized schema binary. The default value is "`%SYSTEMROOT%\System32`".

### `QPMO_LOCALIZED_SCHEMA_BINARY_PATH`

A **VT_LPWSTR** containing the full path to the folder that contains the localized schema binary that can be read and written to as needed. The default value is "`%LOCALAPPDATA%\Microsoft\Windows`".

### `QPMO_APPEND_LCID_TO_LOCALIZED_PATH`

A **VT_BOOL**. If **TRUE**, then the paths for pre-localized and localized binaries have "`\(LCID)`" appended to them, where LCID is the decimal locale ID for the localized language. The default is **TRUE**.

### `QPMO_LOCALIZER_SUPPORT`

A **VT_UNKNOWN** with an object supporting [ISchemaLocalizerSupport](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemalocalizersupport). This object will be used instead of the default localizer support object.