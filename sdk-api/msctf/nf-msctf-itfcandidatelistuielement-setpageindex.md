# ITfCandidateListUIElement::SetPageIndex

## Description

The **ITfCandidateListUIElement::SetPageIndex** method sets the page index.

## Parameters

### `pIndex` [in]

[in] A pointer to an array of the indexes that each page starts from.

### `uPageCnt` [in]

[in] A page count. The size of the pIndex buffer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |