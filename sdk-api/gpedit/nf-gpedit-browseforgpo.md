# BrowseForGPO function

## Description

The
**BrowseForGPO** function creates a GPO browser dialog box that allows the user to open or create a GPO.

## Parameters

### `lpBrowseInfo` [in, out]

A pointer to a
[GPOBROWSEINFO](https://learn.microsoft.com/windows/win32/api/gpedit/ns-gpedit-gpobrowseinfo) structure that contains information used to initialize the dialog box. When
the **BrowseForGPO** function returns, this structure contains information about the user's actions.

## Return value

If the function succeeds, the return value is **S_OK**. If the user cancels or closes the dialog box, the return value is **HRESULT_FROM_WIN32**(**ERROR_CANCELLED**). Otherwise, the function returns one of the COM error codes defined in the header file WinError.h.

## See also

[GPOBROWSEINFO](https://learn.microsoft.com/windows/win32/api/gpedit/ns-gpedit-gpobrowseinfo)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)