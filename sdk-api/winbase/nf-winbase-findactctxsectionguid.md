# FindActCtxSectionGuid function

## Description

The
**FindActCtxSectionGuid** function retrieves information on a specific GUID in the current activation context and returns a
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

Identifier of the section of the activation context in which to search for the specified GUID.

The following are valid GUID section identifiers:

* ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION
* ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION
* ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION

The following is a valid GUID section identifier beginning with Windows Server 2003 and Windows XP with SP1:

* ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES

### `lpGuidToFind` [in]

Pointer to a GUID to be used as the search criteria.

### `ReturnedData` [out]

Pointer to an
[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data) structure to be filled out with the requested GUID information.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function should only be called by the Side-by-side API functions or COM methods. Applications should not directly call this function.

## See also

[ACTCTX_SECTION_KEYED_DATA](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctx_section_keyed_data)

[FindActCtxSectionString](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findactctxsectionstringa)