# FAX_LOG_CATEGORYA structure

## Description

The **FAX_LOG_CATEGORY** structure describes one logging category. The structure contains a logging category name and identifier. It also includes the current level at which the fax server logs events for the specified logging category in the application event log.

## Members

### `Name`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is a descriptive name for the logging category.

### `Category`

Type: **DWORD**

Specifies a **DWORD** variable that is a unique value that identifies a logging category. This member can be one of the following predefined values.

#### FAXLOG_CATEGORY_INIT

A fax service initialization or termination event.

#### FAXLOG_CATEGORY_OUTBOUND

An outgoing fax transmission event such as sending a fax.

#### FAXLOG_CATEGORY_INBOUND

An incoming fax transmission event such as receiving a fax or routing a fax.

#### FAXLOG_CATEGORY_UNKNOWN

An unknown event.

### `Level`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the current logging level for the logging category. This member can be one of the following predefined logging levels.

#### FAXLOG_LEVEL_NONE

The fax server does not log events.

#### FAXLOG_LEVEL_MIN

The fax server logs only the most severe failure events.

#### FAXLOG_LEVEL_MED

The fax server logs most events. (This level does not include some informational and warning events.)

#### FAXLOG_LEVEL_MAX

The fax server logs all events.

## Remarks

The fax client application passes the **FAX_LOG_CATEGORY** structure in a call to the [FaxSetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetloggingcategoriesa) function to modify the current logging categories for the fax server of interest. If the application calls the [FaxGetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetloggingcategoriesa) function, it returns the current settings in a **FAX_LOG_CATEGORY** structure. For more information, see [Managing Logging Categories](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-logging-categories).

> [!NOTE]
> The winfax.h header defines FAX_LOG_CATEGORY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxGetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetloggingcategoriesa)

[FaxSetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetloggingcategoriesa)