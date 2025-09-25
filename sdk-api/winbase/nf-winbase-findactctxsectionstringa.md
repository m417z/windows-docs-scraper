# FindActCtxSectionStringA function

## Description

The
**FindActCtxSectionString** function retrieves information on a specific string in the current activation context and returns a
[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data) structure.

## Parameters

### `dwFlags` [in]

Flags that determine how this function is to operate. Only the following flag is currently defined.

| Value | Meaning |
| --- | --- |
| **FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX** | This function returns the activation context handle where the redirection data was found in the **hActCtx** member of the [ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data) structure. The caller must use [ReleaseActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-releaseactctx) to release this activation context. |

### `lpExtensionGuid` [in]

Reserved; must be null.

### `ulSectionId` [in]

Identifier of the string section of the activation context in which to search for the specific string.

The following are valid string section identifiers:

* ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION
* ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION
* ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION
* ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION

### `lpStringToFind` [in]

Pointer to a null-terminated string to be used as the search criteria.

### `ReturnedData` [out]

Pointer to an
[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data) structure to be filled out with the requested string information.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function should only be called by the Side-by-side API functions or COM methods. Applications should not directly call this function.

> [!NOTE]
> The winbase.h header defines FindActCtxSectionString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data)

[FindActCtxSectionGuid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionguid)