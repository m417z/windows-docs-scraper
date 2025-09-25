# WsGetXmlAttribute function

## Description

Finds the nearest xml attribute in scope with the specified localName and returns its value.
The returned value is placed on the specified heap.

## Parameters

### `reader` [in]

The reader for which the xml attribute will be searched.

### `localName` [in]

The localName of the xml attribute for which to search.

### `heap` [in]

The heap on which the resulting value should be allocated.

### `valueChars`

The value of the attribute is stored here.

### `valueCharCount` [out]

The length of the valueChars.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **S_FALSE** | The xml attribute was not found. |

## Remarks

This function may only be used to obtain the values of attributes in scope that use the prefix "xml".

If no matching xml attribute is found, a zero length string will be returned for the value, and the
function returns S_FALSE.

The reader does not do anything with xml attributes other than to surface them for inspection.