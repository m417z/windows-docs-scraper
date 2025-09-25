# GET_APPCOMMAND_LPARAM macro

## Syntax

```cpp
short GET_APPCOMMAND_LPARAM(
    LPARAM lParam
);
```

## Return value

Type: **short**

The return value is the bits of the high-order word representing the application command. It can be one of the following values.

## Description

Retrieves the application command from the specified **LPARAM** value.

## Parameters

### `lParam`

The value to be converted.

## See also

[Mouse Input Overview](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)