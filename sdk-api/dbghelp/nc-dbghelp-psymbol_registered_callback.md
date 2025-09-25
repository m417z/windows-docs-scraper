# PSYMBOL_REGISTERED_CALLBACK callback function

## Description

An application-defined callback function used with the
[SymRegisterCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregistercallback) function. It is called by the symbol handler.

The **PSYMBOL_REGISTERED_CALLBACK64** type defines a pointer to this callback function.
**SymRegisterCallbackProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ActionCode` [in]

The callback code. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CBA_DEBUG_INFO**<br><br>0x10000000 | Display verbose information.<br><br>The *CallbackData* parameter is a pointer to a string. |
| **CBA_DEFERRED_SYMBOL_LOAD_CANCEL**<br><br>0x00000007 | Deferred symbol loading has started. To cancel the symbol load, return **TRUE**. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load) structure. |
| **CBA_DEFERRED_SYMBOL_LOAD_COMPLETE**<br><br>0x00000002 | Deferred symbol load has completed. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load) structure. |
| **CBA_DEFERRED_SYMBOL_LOAD_FAILURE**<br><br>0x00000003 | Deferred symbol load has failed. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load) structure. The symbol handler will attempt to load the symbols again if the callback function sets the **FileName** member of this structure. |
| **CBA_DEFERRED_SYMBOL_LOAD_PARTIAL**<br><br>0x00000020 | Deferred symbol load has partially completed. The symbol loader is unable to read the image header from either the image file or the specified module.<br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load) structure. The symbol handler will attempt to load the symbols again if the callback function sets the **FileName** member of this structure.<br><br>**DbgHelp 5.1:** This value is not supported. |
| **CBA_DEFERRED_SYMBOL_LOAD_START**<br><br>0x00000001 | Deferred symbol load has started. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load) structure. |
| **CBA_DUPLICATE_SYMBOL**<br><br>0x00000005 | Duplicate symbols were found. This reason is used only in COFF or CodeView format. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_DUPLICATE_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_duplicate_symbol) structure. To specify which symbol to use, set the **SelectedSymbol** member of this structure. |
| **CBA_EVENT**<br><br>0x00000010 | Display verbose information. If you do not handle this event, the information is resent through the CBA_DEBUG_INFO event.<br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_CBA_EVENT](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_event) structure. |
| **CBA_READ_MEMORY**<br><br>0x00000006 | The loaded image has been read. <br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_CBA_READ_MEMORY](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_read_memory) structure. The callback function should read the number of bytes specified by the **bytes** member into the buffer specified by the **buf** member, and update the **bytesread** member accordingly. |
| **CBA_SET_OPTIONS**<br><br>0x00000008 | Symbol options have been updated. To retrieve the current options, call the [SymGetOptions](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetoptions) function. <br><br>The *CallbackData* parameter should be ignored. |
| **CBA_SRCSRV_EVENT**<br><br>0x40000000 | Display verbose information for source server. If you do not handle this event, the information is resent through the CBA_DEBUG_INFO event.<br><br>The *CallbackData* parameter is a pointer to a [IMAGEHLP_CBA_EVENT](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_event) structure.<br><br>**DbgHelp 6.6 and earlier:** This value is not supported. |
| **CBA_SRCSRV_INFO**<br><br>0x20000000 | Display verbose information for source server.<br><br>The *CallbackData* parameter is a pointer to a string.<br><br>**DbgHelp 6.6 and earlier:** This value is not supported. |
| **CBA_SYMBOLS_UNLOADED**<br><br>0x00000004 | Symbols have been unloaded. <br><br>The *CallbackData* parameter should be ignored. |

### `CallbackData` [in, optional]

Data for the operation. The format of this data depends on the value of the *ActionCode* parameter.

If the callback function was registered with [SymRegisterCallbackW64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregistercallback), the data is a Unicode string or data structure. Otherwise, the data uses ANSI format.

### `UserContext` [in, optional]

User-defined value specified in
[SymRegisterCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregistercallback), or **NULL**. Typically, this parameter is used by an application to pass a pointer to a data structure that lets the callback function establish some context.

## Return value

To indicate success handling the code, return **TRUE**.

To indicate failure handling the code, return **FALSE**. If your code does not handle a particular code, you should also return **FALSE**. (Returning **TRUE** in this case may have unintended consequences.)

## Remarks

The calling application gets called through the registered callback function as a result of another call to one of the symbol handler functions. The calling application must be prepared for the possible side effects that this can cause. If the application has only one callback function that is being used by multiple threads, then care may be necessary to synchronize some types of data access while in the context of the callback function.

This callback function supersedes the *PSYMBOL_REGISTERED_CALLBACK* callback function. *PSYMBOL_REGISTERED_CALLBACK* is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PSYMBOL_REGISTERED_CALLBACK PSYMBOL_REGISTERED_CALLBACK64
#else
typedef BOOL
(CALLBACK *PSYMBOL_REGISTERED_CALLBACK)(
    __in HANDLE hProcess,
    __in ULONG ActionCode,
    __in_opt PVOID CallbackData,
    __in_opt PVOID UserContext
    );
#endif
```

For a more extensive example, read [Getting Notifications](https://learn.microsoft.com/windows/desktop/Debug/getting-notifications).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[Getting Notifications](https://learn.microsoft.com/windows/desktop/Debug/getting-notifications)

[IMAGEHLP_CBA_EVENT](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_event)

[IMAGEHLP_CBA_READ_MEMORY](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_read_memory)

[IMAGEHLP_DEFERRED_SYMBOL_LOAD64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_deferred_symbol_load)

[IMAGEHLP_DUPLICATE_SYMBOL64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_duplicate_symbol)

[SymRegisterCallback64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symregistercallback)