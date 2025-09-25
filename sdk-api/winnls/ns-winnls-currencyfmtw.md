# CURRENCYFMTW structure

## Description

Contains information that defines the format of a currency string. The [GetCurrencyFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformata) function uses this information to customize a currency string for a specified locale.

## Members

### `NumDigits`

Number of fractional digits. This number is equivalent to [LOCALE_ICURRDIGITS](https://learn.microsoft.com/windows/desktop/Intl/locale-icurrdigits).

### `LeadingZero`

Value indicating if leading zeros should be used in decimal fields. This value is equivalent to [LOCALE_ILZERO](https://learn.microsoft.com/windows/desktop/Intl/locale-ilzero).

### `Grouping`

Number of digits in each group of numbers to the left of the decimal separator specified by **lpDecimalSep**. The most significant grouping digit indicates the number of digits in the least significant group immediately to the left of the decimal separator. Each subsequent grouping digit indicates the next significant group of digits to the left of the previous group. If the last value supplied is not 0, the remaining groups repeat the last group. Typical examples of settings for this member are: 0 to group digits as in 123456789.00; 3 to group digits as in 123,456,789.00; and 32 to group digits as in 12,34,56,789.00.

**Note** You can use settings other than the typical settings, but they will not show up in the regional and language settings portion of the Control Panel. Such settings are extremely uncommon and might have unexpected results.

### `lpDecimalSep`

Pointer to a null-terminated decimal separator string.

### `lpThousandSep`

Pointer to a null-terminated thousand separator string.

### `NegativeOrder`

Negative currency mode. This mode is equivalent to [LOCALE_INEGCURR](https://learn.microsoft.com/windows/desktop/Intl/locale-ineg-constants).

### `PositiveOrder`

Positive currency mode. This mode is equivalent to [LOCALE_ICURRENCY](https://learn.microsoft.com/windows/desktop/Intl/locale-icurrency).

### `lpCurrencySymbol`

Pointer to a null-terminated currency symbol string.

## See also

[GetCurrencyFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformata)

[National Language Support Structures](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-structures)

## Remarks

> [!NOTE]
> The winnls.h header defines CURRENCYFMT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).