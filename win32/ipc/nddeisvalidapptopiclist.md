# NDdeIsValidAppTopicList function

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Determines whether an application and topic string ("*AppName*\|*TopicName*") uses the proper syntax.

## Parameters

*targetTopic* \[in\]

A pointer to the application and topic string to validate. This parameter cannot be **NULL**.

## Return value

If the *targetTopic* parameter has valid syntax, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This function is also called by [**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd) when it creates the DDE share.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |
| Library<br> | Nddeapi.lib |
| DLL<br> | Nddeapi.dll |
| Unicode and ANSI names<br> | **NDdeIsValidAppTopicListW** (Unicode) and **NDdeIsValidAppTopicListA** (ANSI)<br> |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Functions](https://learn.microsoft.com/windows/win32/ipc/network-dde-functions)

[**NDdeShareAdd**](https://learn.microsoft.com/windows/win32/ipc/nddeshareadd)

