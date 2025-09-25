# VerQueryValueA function

## Description

Retrieves specified version information from the specified version-information resource. To retrieve the appropriate resource, before you call **VerQueryValue**, you must first call the [GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea) function, and then the [GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa) function.

## Parameters

### `pBlock` [in]

Type: **LPCVOID**

The version-information resource returned by the [GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa) function.

### `lpSubBlock` [in]

Type: **LPCTSTR**

The version-information value to be retrieved. The string must consist of names separated by backslashes (\\) and it must have one of the following forms.

#### \

The root block. The function retrieves a pointer to the [VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure for the version-information resource.

#### \VarFileInfo\Translation

The translation array in a [Var](https://learn.microsoft.com/windows/desktop/menurc/var-str) variable information structure—the **Value** member of this structure. The function retrieves a pointer to this array of language and code page identifiers. An application can use these identifiers to access a language-specific [StringTable](https://learn.microsoft.com/windows/desktop/menurc/stringtable) structure (using the **szKey** member) in the version-information resource.

#### \StringFileInfo\lang-codepage\string-name

A value in a language-specific [StringTable](https://learn.microsoft.com/windows/desktop/menurc/stringtable) structure. The *lang-codepage* name is a concatenation of a language and code page identifier pair found as a **DWORD** in the translation array for the resource. Here the *lang-codepage* name must be specified as a hexadecimal string. The *string-name* name must be one of the predefined strings described in the following Remarks section. The function retrieves a string value specific to the language and code page indicated.

### `lplpBuffer` [out]

Type: **LPVOID***

When this method returns, contains the address of a pointer to the requested version information in the buffer pointed to by *pBlock*. The memory pointed to by *lplpBuffer* is freed when the associated *pBlock* memory is freed.

### `puLen` [out]

Type: **PUINT**

When this method returns, contains a pointer to the size of the requested data pointed to by *lplpBuffer*: for version information values, the length in characters of the string stored at *lplpBuffer*; for translation array values, the size in bytes of the array stored at *lplpBuffer*; and for root block, the size in bytes of the structure.

## Return value

Type: **BOOL**

If the specified version-information structure exists, and version information is available, the return value is nonzero. If the address of the length buffer is zero, no value is available for the specified version-information name.

If the specified name does not exist or the specified resource is not valid, the return value is zero.

## Remarks

 This function works on 16-, 32-, and 64-bit file images.

The following are predefined version information Unicode strings.

|  |  |  |
| --- | --- | --- |
| Comments | InternalName | ProductName |
| CompanyName | LegalCopyright | ProductVersion |
| FileDescription | LegalTrademarks | PrivateBuild |
| FileVersion | OriginalFilename | SpecialBuild |

#### Examples

The following example shows how to enumerate the available version languages and retrieve the FileDescription string-value for each language.

Be sure to call the [GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea) and [GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa) functions before calling **VerQueryValue** to properly initialize the *pBlock* buffer.

```cpp
// Structure used to store enumerated languages and code pages.

HRESULT hr;

struct LANGANDCODEPAGE {
  WORD wLanguage;
  WORD wCodePage;
} *lpTranslate;

// Read the list of languages and code pages.

VerQueryValue(pBlock,
              TEXT("\\VarFileInfo\\Translation"),
              (LPVOID*)&lpTranslate,
              &cbTranslate);

// Read the file description for each language and code page.

for( i=0; i < (cbTranslate/sizeof(struct LANGANDCODEPAGE)); i++ )
{
  hr = StringCchPrintf(SubBlock, 50,
            TEXT("\\StringFileInfo\\%04x%04x\\FileDescription"),
            lpTranslate[i].wLanguage,
            lpTranslate[i].wCodePage);
	if (FAILED(hr))
	{
	// TODO: write error handler.
	}

  // Retrieve file description for language and code page "i".
  VerQueryValue(pBlock,
                SubBlock,
                &lpBuffer,
                &dwBytes);
}
```

> [!NOTE]
> The winver.h header defines VerQueryValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa)

[GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea)

**Reference**

[String](https://learn.microsoft.com/windows/desktop/menurc/string-str)

[StringFileInfo](https://learn.microsoft.com/windows/desktop/menurc/stringfileinfo)

[StringTable](https://learn.microsoft.com/windows/desktop/menurc/stringtable)

[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[Var](https://learn.microsoft.com/windows/desktop/menurc/var-str)

[VarFileInfo](https://learn.microsoft.com/windows/desktop/menurc/varfileinfo)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)