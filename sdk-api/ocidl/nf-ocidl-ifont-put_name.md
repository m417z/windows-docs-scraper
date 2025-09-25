# IFont::put_Name

## Description

Specifies a new name for the font family.

## Parameters

### `name` [in]

The new name of the font family. This value is both allocated and freed by
the caller.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the
following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The name was changed successfully. |
| **E_POINTER** | The address in the *name* parameter is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

The string value is caller allocated and the caller is responsible for freeing it after this call
returns.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::get_Name](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-get_name)