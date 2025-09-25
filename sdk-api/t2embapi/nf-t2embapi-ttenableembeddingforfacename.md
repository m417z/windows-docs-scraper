# TTEnableEmbeddingForFacename function

## Description

Adds or removes facenames from the typeface exclusion list.

## Parameters

### `lpszFacename` [in]

Pointer to the facename of the font to be added or removed from the typeface exclusion list.

### `bEnable` [in]

Boolean controlling operation on typeface exclusion list. If nonzero, then the facename will be removed from the list; if zero, the facename will be added to the list.

## Return value

If successful, returns E_NONE.

The facename indicated by *lpszFacename* will be added or removed from the typeface exclusion list.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

The function **TTEnableEmbeddingForFacename** uses a typeface exclusion list to control whether a specific font can be embedded. This list identifies all fonts that should NOT be embedded and is shared by all authoring clients on a single system.

An authoring client can embed fonts without referencing the typeface exclusion list (that is, without using **TTEnableEmbeddingForFacename**). Embedding fonts in a document results in the following tradeoffs.

* Provides all font information within a document so the appropriate client can render the document.
* Adds size to a document.
* Complicates streaming read and write operations to a document and uses more processing bandwidth.
* Makes a document less readable by other applications.
* Can leave copyright issues unmanaged, if the type exclusion list is not used.

Two additional functions, [TTIsEmbeddingEnabled](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabled) and [TTIsEmbeddingEnabledForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabledforfacename), access the typeface exclusion list to provide enabling status.

The typeface exclusion list is stored in the registry key **HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Shared Tools\t2embed**. The default typeface exclusion list should contain the following named value entries representing the Microsoft Windows core fonts.

| Value name | Data type | Data value |
| --- | --- | --- |
| Arial | REG_DWORD | 0 |
| Arial Bold | REG_DWORD | 0 |
| Arial Bold Italic | REG_DWORD | 0 |
| Arial Italic | REG_DWORD | 0 |
| Courier New | REG_DWORD | 0 |
| Courier New Bold | REG_DWORD | 0 |
| Courier New Bold Italic | REG_DWORD | 0 |
| Courier New Italic | REG_DWORD | 0 |
| Times New Roman | REG_DWORD | 0 |
| Times New Roman Bold | REG_DWORD | 0 |
| Times New Roman Bold Italic | REG_DWORD | 0 |
| Times New Roman Italic | REG_DWORD | 0 |

## See also

[TTIsEmbeddingEnabled](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabled)

[TTIsEmbeddingEnabledForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabledforfacename)