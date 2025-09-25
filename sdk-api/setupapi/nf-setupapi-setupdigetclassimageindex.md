# SetupDiGetClassImageIndex function

## Description

The **SetupDiGetClassImageIndex** function retrieves the index within the class image list of a specified class.

## Parameters

### `ClassImageListData` [in]

A pointer to an [SP_CLASSIMAGELIST_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classimagelist_data) structure that describes a class image list that includes the image for the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) that is specified by the *ClassGuid* parameter.

### `ClassGuid` [in]

A pointer to the GUID of the device setup class for which to retrieve the index of the class image in the specified class image list.

### `ImageIndex` [out]

A pointer to an INT-typed variable that receives the index of the specified class image in the class image list.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified device setup class is not included in the specified class image list, **SetupDiGetClassImageIndex** returns the image index for the Unknown device setup class in the *ImageIndex* parameter.

## See also

[SetupDiGetClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelist)

[SetupDiGetClassImageListEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelistexa)