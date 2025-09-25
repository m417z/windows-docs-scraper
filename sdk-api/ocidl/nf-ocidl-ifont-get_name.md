# IFont::get_Name

## Description

Retrieves the name of the font family.

## Parameters

### `pName` [out]

A pointer to the caller-allocated variable that receives the name. This string must be freed with **SysFreeString** when it is no longer needed.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The name was returned successfully. |
| **E_POINTER** | The address in the *pname* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Name](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_name)