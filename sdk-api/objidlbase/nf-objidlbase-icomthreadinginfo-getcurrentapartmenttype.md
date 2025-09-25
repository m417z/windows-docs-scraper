# IComThreadingInfo::GetCurrentApartmentType

## Description

Retrieves the type of apartment in which the caller is executing.

## Parameters

### `pAptType` [out]

A points to an [APTTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttype) enumeration value that characterizes the caller's apartment.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The caller is not executing in an apartment. |

## See also

[IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo)