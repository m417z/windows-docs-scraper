# DLLGetDocumentation function

Retrieves a localized string for a given help context value.

## Parameters

`ptlib`

The TypeLib associated with help context.

`ptinfo`

The TypeInfo associated with help context.

`lcid`

Windows Language Code Identifier.

`dwCtx`

Cookie value representing the help context id being looked for.

`pbstrHelpString`

Localized help string associated with the context id passed in.

## Return value

This function doesn't return a value.

## Remarks

For more info, see [To specify localized help strings](https://github.com/MicrosoftDocs/visualstudio-docs/blob/main/docs/extensibility/internals/properties-window-fields-and-interfaces.md#to-specify-localized-help-strings) on GitHub.

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | N/A |
| **Library** | N/A |
| **DLL** | Unknown |

## See also

* [To specify localized help strings](https://github.com/MicrosoftDocs/visualstudio-docs/blob/main/docs/extensibility/internals/properties-window-fields-and-interfaces.md#to-specify-localized-help-strings) on GitHub