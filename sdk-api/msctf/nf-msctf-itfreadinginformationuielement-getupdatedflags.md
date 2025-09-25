# ITfReadingInformationUIElement::GetUpdatedFlags

## Description

This method returns the flag that tells which part of this element was updated.

## Parameters

### `pdwFlags` [out]

[out] A pointer to receive the flags that is a combination of the following bits:

| Value | Meaning |
| --- | --- |
| **TF_RIUIE_CONTEXT** | The target [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) was changed. |
| **TF_RIUIE_STRING** | The reading information string was changed. |
| **TF_RIUIE_MAXREADINGSTRINGLENGTH** | The max length of the reading information string was changed. |
| **TF_RIUIE_ERRORINDEX** | The error index of the reading information string was changed. |
| **TF_RIUIE_VERTICALORDER** | The vertical order preference was changed. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |