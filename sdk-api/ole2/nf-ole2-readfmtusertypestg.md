# ReadFmtUserTypeStg function

## Description

The
**ReadFmtUserTypeStg** function returns the clipboard format and user type previously saved with the
[WriteFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-writefmtusertypestg) function.

## Parameters

### `pstg` [in]

Pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object from which the information is to be read.

### `pcf` [out]

Pointer to where the clipboard format is to be written on return. It can be **NULL**, indicating the format is of no interest to the caller.

### `lplpszUserType` [out]

Address of **LPWSTR** pointer variable that receives a pointer to the null-terminated Unicode user-type string. The caller can specify **NULL** for this parameter, which indicates that the user type is of no interest. This function allocates memory for the string. The caller is responsible for freeing the memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

This function supports the standard return values E_FAIL, E_INVALIDARG, and E_OUTOFMEMORY, in addition to the following:

This function also returns any of the error values returned by the
[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) method.

## Remarks

**ReadFmtUserTypeStg** returns the clipboard format and the user type string from the specified storage object. The
[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) function must have been called before calling the
**ReadFmtUserTypeStg** function.

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[WriteFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-writefmtusertypestg)