# IMFMetadata::GetAllLanguages

## Description

Gets a list of the languages in which metadata is available.

## Parameters

### `ppvLanguages` [out]

A pointer to a **PROPVARIANT** that receives the list of languages. The list is returned as an array of null-terminated wide-character strings. Each string in the array is an RFC 1766-compliant language tag.

The returned **PROPVARIANT** type is VT_VECTOR | VT_LPWSTR. The list might be empty, if no language tags are present. The caller must free the **PROPVARIANT** by calling [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about language tags, see RFC 1766, "Tags for the Identification of Languages".

To set the current language, call [IMFMetadata::SetLanguage](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmetadata-setlanguage).

#### Examples

The following example shows how to get the list of language tags and enumerate the list.

```cpp
HRESULT DisplayLanguageList(IMFMetadata *pMetadata)
{
    PROPVARIANT varLangs;

    HRESULT hr = pMetadata->GetAllLanguages(&varLangs);
    if (SUCCEEDED(hr))
    {
        if (varLangs.vt == (VT_VECTOR | VT_LPWSTR))
        {
            for (ULONG i = 0; i < varLangs.calpwstr.cElems; i++)
            {
                wprintf(L"%s\n", varLangs.calpwstr.pElems[i]);
            }
        }
        else
        {
            hr = E_UNEXPECTED;
        }
        PropVariantClear(&varLangs);
    }
    return hr;
}

```

## See also

[IMFMetadata](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmetadata)

[Media Metadata](https://learn.microsoft.com/windows/desktop/medfound/media-metadata)