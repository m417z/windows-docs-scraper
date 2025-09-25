# ISnapinHelp::GetHelpTopic

## Description

Enables a snap-in to add its compiled HTML Help file to the MMC Help collection file.

## Parameters

### `lpCompiledHelpFile` [out]

A pointer to the address of the null-terminated Unicode string that contains the path of the compiled Help file (.chm) for the snap-in. When specifying the path, place the file anywhere and specify the full path name.

## Return value

This method can return one of these values.

## Remarks

MMC calls the snap-in's implementation of this method to get the location of the snap-in's Help file. MMC merges the HTML Help files of all snap-ins with the MMC console HTML Help collection file.

The topic hierarchy from the snap-in's Help file will appear in the table of contents when the collection is viewed.

By merging the HTML Help files, MMC creates a single, integrated HTML Help table of contents, index, and search feature. When a user clicks Help on Microsoft Management Console on the main
**Help** menu, MMC opens the merged Help file that includes HTML Help files for all snap-ins in the current console file.

Allocate the *lpCompiledHelpFile* string with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release it.

#### Examples

```cpp
STDMETHODIMP CComponentData::GetHelpTopic( LPOLESTR *lpCompiledFile )
{
    LPOLESTR lpHelpFile;

    if ( !lpCompiledFile )
        return E_POINTER; // invalid argument

    lpHelpFile = (LPOLESTR) CoTaskMemAlloc( MAX_PATH * sizeof(WCHAR) );

    if ( !lpHelpFile )
    {
        return E_OUTOFMEMORY;
    }

    ExpandEnvironmentStringsW( L"%SystemRoot%\\Help\\myhelpfile.chm", lpHelpFile, MAX_PATH );

    *lpCompiledHelpFile = lpHelpFile;

    return S_OK;
}
```

## See also

[Adding HTML Help Support](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-html-help-support)

[IDisplayHelp::ShowTopic](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-idisplayhelp-showtopic)

[ISnapinHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinhelp)

[MMCPropertyHelp](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-mmcpropertyhelp)

[Providing MUI-Compliant Help Files](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/providing-mui-compliant-help-files)