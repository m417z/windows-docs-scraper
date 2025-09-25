# SetupDiDestroyClassImageList function

## Description

The **SetupDiDestroyClassImageList** function destroys a class image list that was built by a call to [SetupDiGetClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelist) or [SetupDiGetClassImageListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelistexa).

## Parameters

### `ClassImageListData` [in]

A pointer to an [SP_CLASSIMAGELIST_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classimagelist_data) structure that contains the class image list to destroy.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SetupDiGetClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelist)

[SetupDiGetClassImageListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelistexa)