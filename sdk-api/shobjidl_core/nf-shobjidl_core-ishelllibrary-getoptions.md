# IShellLibrary::GetOptions

## Description

Gets the library's options.

## Parameters

### `plofOptions` [out]

Type: **[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags)***

The library options for this library. [LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags) is a bitwise enumerator, which means that more than one flag could be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[LIBRARYOPTIONFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryoptionflags)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))