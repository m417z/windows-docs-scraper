## Description

The [InputScope](https://learn.microsoft.com/windows/win32/api/inputscope/ne-inputscope-inputscope) enumeration contains values that specify which input scopes are applied to a given field.

## Constants

### `IS_DEFAULT:0`

Indicates the standard recognition bias. Treated as default and uses the default lexicon. If combined with another input scope, it does not force coercion on the other input scope.

### `IS_URL:1`

Indicates a URL, File, or FTP format. Examples include the following.

* http://www.humongousinsurance.com/
* ftp://ftp.microsoft.com
* www.microsoft.com
* file:///C:\templ.txt
* $

### `IS_FILE_FULLFILEPATH:2`

Indicates a file path. The following conditions are enforced.

* For server name and share name, allows all IS_ONECHAR characters except: * ? : < > |
* For file name, allows all IS_ONECHAR characters except: \ / : < > |
* Input must start with \\ or drive name or \ or ..\ or .\ or /
* Spaces are allowed.

Examples include the following.

* \\servername\sharename\filename.txt
* C:\temp\current work.doc
* ../images/hank.jpg

### `IS_FILE_FILENAME:3`

Indicates a file name. The following conditions are enforced.

* Accepts either extension or no extension.
* Allows all IS_ONECHAR characters except: \ / : < > |
* Spaces are allowed.

Examples include the following:

* filename.txt
* filename
* file name.txt

### `IS_EMAIL_USERNAME:4`

Indicates email user names. Examples include the following.

* jeffsm
* JeffSm
* Jsmith
* JSmith
* jeffsmith

### `IS_EMAIL_SMTPEMAILADDRESS:5`

Indicates a complete SMTP email address, for example, someone@example.com.

### `IS_LOGINNAME:6`

Indicates a log-in name and domain. The following conditions are enforced.

* Allows all IS_ONECHAR characters.
* Does not allow domain or username to start or end in a non-alphanumeric character.
* Spaces are not allowed.

Examples include the following.

* CHICAGO\JSMITH
* JSMITH

### `IS_PERSONALNAME_FULLNAME:7`

Indicates a combination of first, middle, and last names. Examples include the following, formatted for English (United States).

* Mr. Jeff A. Smith, Jr.
* Jeff Smith
* Smith, Jeff
* Smith, Jeff A

### `IS_PERSONALNAME_PREFIX:8`

Indicates a honorific or title preceding a name. Examples include the following, formatted for English (United States).

* Mr.
* Dr.
* Miss
* Sir

### `IS_PERSONALNAME_GIVENNAME:9`

Indicates a first name or initial. Examples include the following, formatted for English (United States).

* Jeff
* J.
* J.A.

### `IS_PERSONALNAME_MIDDLENAME:10`

Indicates a middle name or initial. Examples include the following.

* Albert
* A.

### `IS_PERSONALNAME_SURNAME:11`

Indicates a last name. Examples include the following, formatted for English (United States).

* Smith
* Smith Jones
* Smith-Jones

### `IS_PERSONALNAME_SUFFIX:12`

Indicates a name suffix abbreviation or Roman numerals. Examples include the following.

* Jr.
* III

### `IS_ADDRESS_FULLPOSTALADDRESS:13`

Indicates a full address, including numbers. Examples include the following, formatted for English (United States).

* 123 Main Street, Anytown, WA 98989
* PO Box 123 Anytown, WA 98989

### `IS_ADDRESS_POSTALCODE:14`

Indicates an alphanumeric postal code. The value is alphanumeric to support international zip codes. Examples include the following, formatted for English (United States).

* 98989
* 98989-1234

### `IS_ADDRESS_STREET:15`

Indicates a house number, street number, apartment name and number, and/or postal box. Examples include the following.

* 123 Main Street
* P.O. Box 1234

### `IS_ADDRESS_STATEORPROVINCE:16`

Indicates a full name or abbreviation of state or province. Examples include the following, formatted for English (United States).

* WA
* Washington
* Wa

### `IS_ADDRESS_CITY:17`

Indicates the name or abbreviation of a city. Examples include the following, formatted for English (United States).

* New York
* NYC

### `IS_ADDRESS_COUNTRYNAME:18`

Indicates the name of a country/region. Examples include the following, formatted for English (United States).

* Italy
* Japan
* United States of America

### `IS_ADDRESS_COUNTRYSHORTNAME:19`

Indicates the abbreviation of the name of a country/region. Examples include the following, formatted for English (United States).

* USA
* U.S.A.

### `IS_CURRENCY_AMOUNTANDSYMBOL:20`

Indicates currency symbols and numbers. Examples include the following, formatted for English (United States).

* $ 2,100.25
* $.35
* $1,234.50 USD

### `IS_CURRENCY_AMOUNT:21`

Indicates a numeric value for currency, excluding currency symbols. For example, 2,100.25.

### `IS_DATE_FULLDATE:22`

Indicates a full date, in a variety of formats. Examples include the following, formatted for English (United States).

* 07-17-2001
* 7/17/01
* 7/17
* Dec. 12
* July 17
* July 17, 2001

### `IS_DATE_MONTH:23`

Indicates a numeric representation of months, constrained to 1-12. Examples include the following.

* 7
* 07
* 11

### `IS_DATE_DAY:24`

Indicates a numeric representation of days, constrained to 1-31. Examples include the following.

* 1
* 04
* 17

### `IS_DATE_YEAR:25`

Indicates a numeric representation of years. Examples include the following.

* 1988
* 2004
* 88
* 04
* '88

### `IS_DATE_MONTHNAME:26`

Indicates a character representation of months. Examples include the following, formatted for English (United States).

* December
* Dec
* Dec.

### `IS_DATE_DAYNAME:27`

Indicates a character representation of days. Examples include the following, formatted for English (United States).

* Wednesday
* Weds
* Weds.

### `IS_DIGITS:28`

Indicates positive whole numbers, constrained to 0-9.

### `IS_NUMBER:29`

Indicates numbers, including commas, negative sign, and decimal. For United States locations, the following conditions are enforced.

* The thousand separator is a comma.
* The decimal separator is a period.
* Negative numbers are represented with a hyphen without a space, not with parentheses.

### `IS_ONECHAR:30`

Indicates a single ANSI character, codepage 1252. For United States locations, this includes the following characters.

ABCDEFGHIJKLMNOPQRSTUVWXYZabcdEfghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

### `IS_PASSWORD:31`

Indicates a password. **IS_PASSWORD** is not supported and may be altered or unavailable in the future.

**Note** **IS_PASSWORD** only indicates the password; it doesn't provide any security around the password. All passwords fields should have text services disabled to maintain password secrecy, and therefore it is not valid to have a password field with an **IS_PASSWORD** input scope.

### `IS_TELEPHONE_FULLTELEPHONENUMBER:32`

Indicates a telephone number. Alphabetical input is not allowed. Examples include the following, formatted for English (United States).

* (206) 555-0123
* 555-0123
* 555.0123
* 206-555-0123
* 1-206-555-0123x1234
* +1 (206) 555-1234

### `IS_TELEPHONE_COUNTRYCODE:33`

Indicates telephone country codes. Examples include the following, formatted for English (United States).

* +1
* +44
* 001
* 00 44

### `IS_TELEPHONE_AREACODE:34`

Indicates telephone area codes. Examples include the following, formatted for English (United States).

* (206)
* 206

### `IS_TELEPHONE_LOCALNUMBER:35`

Indicates a telephone number, excluding country or area code. Examples include the following, formatted for English (United States).

* 555-0123
* 555 0123
* 555.0123

### `IS_TIME_FULLTIME:36`

Indicates hours, minutes, seconds, and alphabetical time abbreviations. US English uses the 12 hour clock. Leading zeros are optional for hours but required for minutes and seconds. Hours are constrained to 0-24; minutes and seconds are constrained to 0-59. Examples include the following, formatted for English (United States).

* 3:20
* 04:30
* 11:20:55
* 11:15 am
* 4:30 AM

### `IS_TIME_HOUR:37`

Indicates a numeric representation of hours, constrained to 0-24.

### `IS_TIME_MINORSEC:38`

Indicates a numeric representation of minutes or seconds, constrained to 0-59.

### `IS_NUMBER_FULLWIDTH:39`

Indicates full-width number, used for Japanese only. Constrained to full-width numbers and Kanji numbers.

### `IS_ALPHANUMERIC_HALFWIDTH:40`

Indicates half-width alphanumeric characters for East-Asian languages, constrained to half-width alphabetical characters and numbers.

### `IS_ALPHANUMERIC_FULLWIDTH:41`

Indicates full-width alphanumeric characters for East-Asian languages, constrained to full-width alphabet characters and numbers.

### `IS_CURRENCY_CHINESE:42`

Indicates Chinese currency.

### `IS_BOPOMOFO:43`

Indicates Bopomofo characters.

### `IS_HIRAGANA:44`

Indicates Hiragana characters.

### `IS_KATAKANA_HALFWIDTH:45`

Indicates half-width Katakana characters.

### `IS_KATAKANA_FULLWIDTH:46`

Indicates full-width Katakana characters.

### `IS_HANJA:47`

Indicates Hanja characters.

### `IS_HANGUL_HALFWIDTH:48`

Indicates half-width Hangul characters.

### `IS_HANGUL_FULLWIDTH:49`

Indicates full-width Hangul characters.

### `IS_SEARCH:50`

**Starting with Windows 8:** Indicates a search string.

### `IS_FORMULA:51`

**Starting with Windows 8:** Indicates a formula control, for example, a spreadsheet field.

### `IS_SEARCH_INCREMENTAL:52`

**Starting with Windows 10:** Indicates input scope is intended for search boxes where incremental results are displayed as the user types.

### `IS_CHINESE_HALFWIDTH:53`

**Starting with Windows 10:** Indicates input scope is intended for Chinese half-width characters.

### `IS_CHINESE_FULLWIDTH:54`

**Starting with Windows 10:** Indicates input scope is intended for Chinese full-width characters.

### `IS_NATIVE_SCRIPT:55`

**Starting with Windows 10:** Indicates input scope is intended for native script.

### `IS_YOMI:56`

**Starting with Windows 10:** Indicates input scope is intended for Japanese names.

### `IS_TEXT:57`

**Starting with Windows 10:** Indicates input scope is intended for working with text.

### `IS_CHAT:58`

**Starting with Windows 10:** Indicates input scope is intended for chat strings.

### `IS_NAME_OR_PHONENUMBER:59`

**Starting with Windows 10:** Indicates input scope is intended for working with a name or telephone number.

### `IS_EMAILNAME_OR_ADDRESS:60`

**Starting with Windows 10:** Indicates input scope is intended for working with an email name or full email address.

### `IS_PRIVATE:61`

**Starting with Windows 10:** Indicates input scope is intended for working with private data.

### `IS_MAPS:62`

**Starting with Windows 10:** Indicates input scope is intended for working with a map location.

### `IS_NUMERIC_PASSWORD:63`

**Starting with Windows 10:** Indicates expected input is a numeric password, or PIN.

### `IS_NUMERIC_PIN:64`

**Starting with Windows 10:** Indicates expected input is a numeric PIN.

### `IS_ALPHANUMERIC_PIN:65`

**Starting with Windows 10:** Indicates expected input is an alphanumeric PIN.

### `IS_ALPHANUMERIC_PIN_SET:66`

**Starting with Windows 10:** Indicates expected input is an alphanumeric PIN for lock screen.

### `IS_FORMULA_NUMBER:67`

**Starting with Windows 10:** Indicates expected input is a mathematical formula.

### `IS_CHAT_WITHOUT_EMOJI:68`

**Starting with Windows 10:** Indicates expected input does not include emoji.

### `IS_PHRASELIST:-1`

Indicates a phrase list.

### `IS_REGULAREXPRESSION:-2`

Indicates a regular expression.

### `IS_SRGS:-3`

Indicates an XML string that conforms to the Speech Recognition Grammar Specification (SRGS) standard. Information on SRGS can be found at [http://www.w3.org/TR/speech-grammar](https://www.w3.org/tr/speech-grammar).

### `IS_XML:-4`

Indicates a custom xml string.

### `IS_ENUMSTRING:-5`

The scope contains the IEnumString interface pointer. The Text Input Processor (TIP) can call [ITfInputScope2::EnumWordList](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-itfinputscope2-enumwordlist) to retrieve it.

## Remarks

Whether a given input scope value is supported can vary across technologies.

## See also

[ITfInputScope](https://learn.microsoft.com/windows/desktop/api/inputscope/nn-inputscope-itfinputscope)

[SetInputScope](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscope)

[SetInputScopeXML](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscopexml)

[SetInputScopes](https://learn.microsoft.com/windows/desktop/api/inputscope/nf-inputscope-setinputscopes)