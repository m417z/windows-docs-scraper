# ITfInputScope::GetRegularExpression

## Description

Gets the regular expression string to be rssecognized.

## Parameters

### `pbstrRegExp` [out]

Pointer to a string containing the regular expression. The calling function must call **SystFreeString()** to free the memory allocated to the strings.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |