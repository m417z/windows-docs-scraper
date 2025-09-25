# ITfCandidateListUIElement::GetString

## Description

The **ITfCandidateListUIElement::GetString** method returns the string of the index.

## Parameters

### `uIndex` [in]

[in] An index of the string to obtain.

### `pstr` [out]

[out] A pointer to BSTR for the candidate string of the index.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |