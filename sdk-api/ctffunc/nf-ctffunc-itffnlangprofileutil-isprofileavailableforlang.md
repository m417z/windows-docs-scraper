# ITfFnLangProfileUtil::IsProfileAvailableForLang

## Description

Determines if the speech text service has a profile available for a specific language.

## Parameters

### `langid` [in]

Contains a **LANGID** that specifies the language that the query applies to.

### `pfAvailable` [out]

Pointer to a **BOOL** that receives nonzero if a profile is available for the language identified by langid or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfAvailable* is invalid. |