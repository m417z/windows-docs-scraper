# IWordBreaker::Init

## Description

Initializes the [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) implementation and indicates the mode in which the component operates.

## Parameters

### `fQuery` [in]

Type: **BOOL**

Flag that indicates the mode in which a word breaker operates. **TRUE** indicates query-time word breaking. **FALSE** indicates index-time word breaking.

### `ulMaxTokenSize` [in]

Type: **ULONG**

Maximum number of characters in words that are added to the [IWordSink](https://learn.microsoft.com/windows/desktop/search/iwordsink). Words that exceed this limit are truncated.

### `pfLicense` [out]

Type: **BOOL***

Pointer to a variable that receives a flag indicating whether there are license restrictions for this [IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker) implementation. **TRUE** indicates that the stemmer is restricted to authorized use only. **FALSE** indicates that this **IWordBreaker** implementation can be used freely.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful completion. |
| **LANGUAGE_E_DATABASE_NOT_FOUND** | One of the components for word breaking cannot be located. |
| **E_INVALIDARG** | Invalid argument. The *pfLicense* parameter is **NULL**. |
| **E_FAIL** | Other errors. |

## Remarks

The functionality of the word breaker is similar in both index creation and querying. Differences are language dependent. If *pfLicense* is **TRUE**, and if you want more information about possible license restrictions, call the [IWordBreaker::GetLicenseToUse](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-istemmer-getlicensetouse) method.

## See also

[IWordBreaker](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordbreaker)