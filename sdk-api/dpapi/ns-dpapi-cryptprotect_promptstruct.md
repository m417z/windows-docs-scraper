# CRYPTPROTECT_PROMPTSTRUCT structure

## Description

The **CRYPTPROTECT_PROMPTSTRUCT** structure provides the text of a prompt and information about when and where that prompt is to be displayed when using the
[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) and
[CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) functions.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwPromptFlags`

**DWORD** flags that indicate when prompts to the user are to be displayed. Current **dwPromptFlags** values are as follows.

| Value | Meaning |
| --- | --- |
| **CRYPTPROTECT_PROMPT_ON_PROTECT** | This flag is used to provide the prompt for the protect phase. |
| **CRYPTPROTECT_PROMPT_ON_UNPROTECT** | This flag can be combined with CRYPTPROTECT_PROMPT_ON_PROTECT to enforce the UI (user interface) policy of the caller. When [CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) is called, the **dwPromptFlags** specified in the [CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) call are enforced. |

### `hwndApp`

Window handle to the parent window.

### `szPrompt`

A string containing the text of a prompt to be displayed.

## See also

[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata)

[CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata)