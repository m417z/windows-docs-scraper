# ITfInputProcessorProfiles::GetCurrentLanguage

## Description

Obtains the identifier of the currently active language.

## Parameters

### `plangid` [out]

Pointer to a **LANGID** value that receives the language identifier of the currently active language.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *plangid* is invalid. |