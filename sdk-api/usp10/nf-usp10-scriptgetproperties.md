# ScriptGetProperties function

## Description

Retrieves information about the current scripts.

## Parameters

### `ppSp` [out]

Pointer to an array of pointers to [SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties) structures indexed by script.

### `piNumScripts` [out]

Pointer to the number of scripts. The valid range for this value is 0 through *piNumScripts*-1.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

See [Determining If a Script Requires Glyph Shaping](https://learn.microsoft.com/windows/desktop/Intl/determining-if-a-script-requires-glyph-shaping) for an example of the use of this function.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)