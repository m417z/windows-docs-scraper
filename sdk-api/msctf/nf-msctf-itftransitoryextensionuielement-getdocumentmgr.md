# ITfTransitoryExtensionUIElement::GetDocumentMgr

## Description

The **ITfTransitoryExtensionUIElement::GetDocumentMgr** method returns the pointer of the transitory document manager.

## Parameters

### `ppdim` [out]

[out] A pointer to receive the [ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr) interface pointer. This document manager object contains a context object that has the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface and contains the text of the transitory extension.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |