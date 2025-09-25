# ITfInputProcessorProfiles::ChangeCurrentLanguage

## Description

Sets the currently active language.

## Parameters

### `langid` [in]

Contains the **LANGID** of the language to make active.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *langid* is an invalid language identifier. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_UNEXPECTED** | No thread manager was created for the calling thread. |