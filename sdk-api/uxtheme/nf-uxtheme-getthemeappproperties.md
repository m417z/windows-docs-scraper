# GetThemeAppProperties function

## Description

Retrieves the property flags that control how visual styles are applied in the current application.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The following return values are bit flags combined with a logical OR operator.

| Return code | Description |
| --- | --- |
| **STAP_ALLOW_NONCLIENT** | Specifies that the nonclient areas of application windows have visual styles applied. |
| **STAP_ALLOW_CONTROLS** | Specifies that controls in application windows have visual styles applied. |
| **STAP_ALLOW_WEBCONTENT** | Specifies that all web content displayed in an application is rendered using visual styles. |

## Remarks

Individual flags can be extracted from the result by combining the result with the logical AND of the desired flag.

Do not call this function during [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) or global objects constructors. This may cause invalid return values.

#### Examples

The example extracts a single flag's state from the function result.

```cpp
DWORD resultFlags = GetThemeAppProperties();
bool ctrlsAreThemed = ((resultFlags & STAP_ALLOW_CONTROLS) != 0);

```

## See also

[SetThemeAppProperties](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-setthemeappproperties)