# IFileDialog::SetFileTypes

## Description

Sets the file types that the dialog can open or save.

## Parameters

### `cFileTypes` [in]

Type: **UINT**

The number of elements in the array specified by *rgFilterSpec*.

### `rgFilterSpec` [in]

Type: **const [COMDLG_FILTERSPEC](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-comdlg_filterspec)***

A pointer to an array of [COMDLG_FILTERSPEC](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-comdlg_filterspec) structures, each representing a file type.

## Return value

Type: **HRESULT**

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | [SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes) has already been called. |
| **E_UNEXPECTED** | The **FOS_PICKFOLDERS** flag was set in the [IFileDialog::SetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setoptions) method. |
| **E_INVALIDARG** | The *rgFilterSpec* parameter is **NULL**. |

## Remarks

When using the **Open** dialog, the file types declared there are used to filter the view. When using the **Save** dialog, these values determine which file name extension is appended to the file name.

This method must be called before the dialog is shown and can only be called once for each dialog instance. File types cannot be modified once the Common Item dialog box is displayed.

#### Examples

The following code example demonstrates the use of the array of [COMDLG_FILTERSPEC](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-comdlg_filterspec) structures in the context of this method. The example array consists of three **COMDLG_FILTERSPEC** structures. The first declares two patterns for the dialog filter, the second declares a single pattern, and the last shows files of all types. The variables szJPG, szBMP, and szAll are assumed to be previously declared strings that provide a friendly name for each filter.

```cpp
COMDLG_FILTERSPEC rgSpec[] =
{
    { szJPG, L"*.jpg;*.jpeg" },
    { szBMP, L"*.bmp" },
    { szAll, L"*.*" },
};
```