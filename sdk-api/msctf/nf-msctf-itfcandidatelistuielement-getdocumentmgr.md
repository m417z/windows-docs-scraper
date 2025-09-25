# ITfCandidateListUIElement::GetDocumentMgr

## Description

The **ITfCandidateListUIElement::GetDocumentMgr** method returns the target document manager of this UI.

## Parameters

### `ppdim` [out]

[out] A pointer to receive [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface pointer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |