# FilterCreate function

## Description

The **FilterCreate** function creates a handle for the given minifilter.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string containing the name of the minifilter. This parameter is required and cannot be **NULL**.

### `hFilter` [out]

Pointer to a caller-allocated variable that receives a handle for the minifilter if the call to **FilterCreate** succeeds; otherwise, it receives INVALID_HANDLE_VALUE.

## Return value

**FilterCreate** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

A user-mode application calls **FilterCreate** to create a handle that can be used to communicate with a kernel-mode minifilter. The returned minifilter handle can be passed as a parameter to functions such as [FilterGetInformation](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetinformation).

To close a filter handle returned by **FilterCreate**, call [FilterClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterclose).

## See also

[FilterClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterclose)

[FilterGetInformation](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtergetinformation)