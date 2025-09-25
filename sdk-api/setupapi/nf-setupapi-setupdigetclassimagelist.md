# SetupDiGetClassImageList function

## Description

The **SetupDiGetClassImageList** function builds an image list that contains bitmaps for every installed class and returns the list in a data structure.

## Parameters

### `ClassImageListData` [out]

A pointer to an [SP_CLASSIMAGELIST_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classimagelist_data) structure to receive information regarding the class image list, including a handle to the image list. The **cbSize** field of this structure must be initialized with the size of the structure, in bytes, before calling this function or it will fail.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The image list built by this function should be destroyed by calling [SetupDiDestroyClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroyclassimagelist).

Call [SetupDiGetClassImageListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelistexa) to retrieve the image list for classes installed on a remote computer.

## See also

[SetupDiDestroyClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroyclassimagelist)

[SetupDiGetClassImageListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelistexa)