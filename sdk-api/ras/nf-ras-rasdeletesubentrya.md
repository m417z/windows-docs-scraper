# RasDeleteSubEntryA function

## Description

The
**RasDeleteSubEntry** function deletes the specified subentry from the specified phone-book entry.

## Parameters

### `pszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file.

### `pszEntry` [in]

Pointer to a **null**-terminated string that contains the name of an existing entry from which a subentry is to be deleted.

### `dwSubentryId`

TBD

### `dwSubEntryId` [in]

Specifies the one-based index of the subentry.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## See also

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RASSUBENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377839(v=vs.85))

[RasDeleteEntry](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdeleteentrya)

## Remarks

> [!NOTE]
> The ras.h header defines RasDeleteSubEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).