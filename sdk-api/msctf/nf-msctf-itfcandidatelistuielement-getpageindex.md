# ITfCandidateListUIElement::GetPageIndex

## Description

The **ITfCandidateListUIElement::GetPageIndex** method returns the page index of the list.

## Parameters

### `pIndex` [out]

[out] A pointer that receives an array of the indexes that each page starts from. This can be **NULL**. The caller calls this method with **NULL** for this parameter first to get the number of pages in *puPageCnt* and allocates the buffer to receive indexes for all pages.

### `uSize` [in]

[in] A buffer size of *pIndex*.

### `puPageCnt` [out]

[out] A pointer to receive the page count.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |