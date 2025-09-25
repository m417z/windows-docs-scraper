# IsStringSupported function

## Description

Returns a value that indicates whether a word, date, time, number, or other text that is passed in is contained in the dictionary.

The results of this test depend on the factoid setting.

## Parameters

### `hrc`

The handle to the recognizer context.

### `wcString`

The count, in Unicode (wide) characters, of *pwcString*.

### `pwcString`

The Unicode (wide) characters to test.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success.<br><br>This function also returns S_OK if the recognizer does not support this function. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **S_FALSE** | The string is not supported. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## Remarks

This function is optional.

The results of this test depend on the factoid setting. For example, if the factoid setting is set to default, then "hello","555-1234", and "10/19/2002" all return S_OK. However, if the factoid is set to TELEPHONE, only "555-1234" returns S_OK, the others return S_FALSE. For more information about factoids, see [Supported Factoids from Version 1](https://learn.microsoft.com/windows/desktop/tablet/supported-factoids-from-version-1).

Note that this function should take into consideration any information specified in [SetTextContext](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-settextcontext) when returning a value. For example, if the recognizer receives calls to SetTextContext ("http:", "") and receives a URL factoid, SetFactoid ((!IS_URL)) then IsStringSupported("www.microsoft.com") should return S_FALSE because it is missing the "//".

The COERCE flag has no effect on IsStringSupported.