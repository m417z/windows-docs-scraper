# IStemmer::Init

## Description

Initializes the stemmer.

## Parameters

### `ulMaxTokenSize` [in]

Type: **ULONG**

Maximum number of characters for words that are added to the [IWordFormSink](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-iwordformsink) object. Words that exceed this limit may be truncated.

### `pfLicense` [out]

Type: **BOOL**

Pointer to an output variable that receives a flag that indicates whether there are license restrictions for this [IStemmer](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-istemmer) implementation. **TRUE** indicates that the stemmer is restricted to authorized use only. **FALSE** indicates that this **IStemmer** implementation can be used freely.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Successful completion. |
| **LANGUAGE_E_DATABASE_NOT_FOUND** | One of the components for word breaking cannot be located. |
| **E_INVALIDARG** | Invalid argument. The *pfLicense* parameter is **NULL**. |
| **E_FAIL** | Unsuccessful completion. |

## Remarks

You must initialize the stemmer. The **IStemmer::Init** method must be called before any other method of [IStemmer](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-istemmer). If *pfLicense* is **TRUE**, and you want more information about possible license restrictions, call the [IStemmer::GetLicenseToUse](https://learn.microsoft.com/windows/desktop/api/indexsrv/nf-indexsrv-istemmer-getlicensetouse) method.

## See also

[IStemmer](https://learn.microsoft.com/windows/desktop/api/indexsrv/nn-indexsrv-istemmer)