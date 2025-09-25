# ITfCandidateListUIElement::GetUpdatedFlags

## Description

The **ITfCandidateListUIElement::GetUpdatedFlags** method returns the flag that tells which part of this element was updated.

## Parameters

### `pdwFlags` [out]

[out] a pointer to receive the flags that is a combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_CLUIE_DOCUMENTMGR** | The target document manager was changed. |
| **TF_CLUIE_COUNT** | The count of the candidate string was changed. |
| **TF_CLUIE_SELECTION** | The selection of the candidate was changed. |
| **TF_CLUIE_STRING** | Some strings in the list were changed. |
| **TF_CLUIE_PAGEINDEX** | The current page index or some page index was changed. |
| **TF_CLUIE_CURRENTPAGE** | The page was changed. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |