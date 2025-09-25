# SetupDiGetClassImageListExA function

## Description

The **SetupDiGetClassImageListEx** function builds an image list of bitmaps for every class installed on a local or remote system.

## Parameters

### `ClassImageListData` [out]

A pointer to an [SP_CLASSIMAGELIST_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classimagelist_data) structure to receive information regarding the class image list, including a handle to the image list. The **cbSize** field of this structure must be initialized with the size of the structure, in bytes, before calling this function or it will fail.

### `MachineName` [in, optional]

A pointer to NULL-terminated string that supplies the name of a remote system for whose classes **SetupDiGetClassImageListEx must build** the bitmap. This parameter is optional and can be **NULL**. If *MachineName* is **NULL**, **SetupDiGetClassImageListEx** builds the list for the local system.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The image list built by this function should be destroyed by calling [SetupDiDestroyClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroyclassimagelist).

**Note** Class-specific icons on a remote computer can only be displayed if the class is also present on the local computer. Thus, if the remote computer has class *X*, but class *X* is not installed locally, then the generic (unknown) icon will be returned.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassImageListEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiDestroyClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdidestroyclassimagelist)

[SetupDiGetClassImageList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassimagelist)