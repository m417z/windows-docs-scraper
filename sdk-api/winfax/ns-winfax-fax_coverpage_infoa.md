# FAX_COVERPAGE_INFOA structure

## Description

The **FAX_COVERPAGE_INFO** structure contains data to display on the cover page of a fax transmission. The **SizeOfStruct** and **CoverPageName** members are required; other members are optional.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_COVERPAGE_INFO** structure. The calling application must set this member to **sizeof(FAX_COVERPAGE_INFO)**.

### `CoverPageName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the name of the cover page file (.cov) to associate with the received fax document. The string can be the file name of the common cover page file, or it can be the UNC path to a local cover page file.

### `UseServerCoverPage`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax cover page file is stored on the local computer or in the common cover page location. A value of **TRUE** indicates that the cover page file resides in the common cover page location on the fax server.

### `RecName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the recipient of the fax transmission.

### `RecFaxNumber`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the fax number of the recipient of the fax transmission.

### `RecCompany`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the company name of the recipient of the fax transmission.

### `RecStreetAddress`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the street address of the recipient of the fax transmission.

### `RecCity`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the city of the recipient of the fax transmission.

### `RecState`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the state of the recipient of the fax transmission.

### `RecZip`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the postal ZIP code of the recipient of the fax transmission.

### `RecCountry`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the country/region of the recipient of the fax transmission.

### `RecTitle`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the title of the recipient of the fax transmission.

### `RecDepartment`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the department of the recipient of the fax transmission.

### `RecOfficeLocation`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the office location of the recipient of the fax transmission.

### `RecHomePhone`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the home telephone number of the recipient of the fax transmission.

### `RecOfficePhone`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the office telephone number of the recipient of the fax transmission.

### `SdrName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the name of the sender who initiated the fax transmission.

### `SdrFaxNumber`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the fax number of the sender who initiated the fax transmission.

### `SdrCompany`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the company name of the sender who initiated the fax transmission.

### `SdrAddress`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the address of the sender who initiated the fax transmission.

### `SdrTitle`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the title of the sender who initiated the fax transmission.

### `SdrDepartment`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the department name of the sender who initiated the fax transmission.

### `SdrOfficeLocation`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the office location of the sender who initiated the fax transmission.

### `SdrHomePhone`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the home telephone number of the sender who initiated the fax transmission.

### `SdrOfficePhone`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the office telephone number of the sender who initiated the fax transmission.

### `Note`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that contains the text of a message or note from the sender that pertains to the fax transmission. The text will appear on the cover page.

### `Subject`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the subject line of the fax transmission.

### `TimeSent`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

Specifies a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. The fax server sets this member when it initiates the fax transmission. The time is expressed in local system time.

### `PageCount`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the total number of pages in the fax transmission.

## Remarks

A fax client application passes the **FAX_COVERPAGE_INFO** structure in a call to the [FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea) function. This enables a user to print a personal cover page at the beginning of a fax transmission. For more information, see [Cover Pages](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-cover-pages) and [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

> [!NOTE]
> The winfax.h header defines FAX_COVERPAGE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa)

[FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)