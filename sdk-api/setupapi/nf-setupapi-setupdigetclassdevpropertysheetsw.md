# SetupDiGetClassDevPropertySheetsW function

## Description

The **SetupDiGetClassDevPropertySheets** function retrieves handles to the property sheets of a device information element or of the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) of a device information set.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to return property sheet handles. If *DeviceInfoData* does not specify a device information element in the device information set, the device information set must have an associated device setup class.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies a device information element in DeviceInfoSet.

This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetClassDevPropertySheets** retrieves the property sheets handles that are associated with the specified device. If this parameter is **NULL**, **SetupDiGetClassDevPropertySheets** retrieves the property sheets handles that are associated with the device setup class specified in *DeviceInfoSet*.

### `PropertySheetHeader` [in]

A pointer to a PROPERTYSHEETHEADER structure. See the **Remarks** section for information about the caller-supplied array of property sheet handles that is associated with this structure.

For more documentation on this structure and property sheets in general, see the Microsoft Windows SDK.

### `PropertySheetHeaderPageListSize` [in]

The maximum number of handles that the caller-supplied array of property sheet handles can hold.

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the number of property sheets that are associated with the specified device information element or the device setup class of the specified device information set. The pointer is optional and can be **NULL**.

### `PropertySheetType` [in]

A flag that indicates one of the following types of property sheets.

| Property sheet type | Meaning |
| --- | --- |
| DIGCDP_FLAG_ADVANCED | Advanced property sheets. |
| DIGCDP_FLAG_BASIC | Basic property sheets. Supported only in Microsoft Windows 95 and Windows 98. Do not use in Windows 2000 and later versions of Windows. |
| DIGCDP_FLAG_REMOTE_ADVANCED | Advanced property sheets on a remote computer. |

## Return value

The function returns **TRUE** if successful. Otherwise, the function returns **FALSE**. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain the error code.

## Remarks

A PROPERTYSHEETHEADER structure contains two members that are associated with a caller-supplied array that the function uses to return the handles of property sheets. The **phpages** member is a pointer to a caller-supplied array of property sheet handles, and the input value of the **nPages** member specifies the number of handles that are already contained in the handle array. The function adds property sheet handles to the handle array beginning with the array element whose array index is the input value of **nPages**. The function adds handles to the array in consecutive order until either the array is full or the handles of all the requested property sheet pages have been added to the array. The maximum number of property sheet handles that the function can return is equal to (*PropertySheetHeaderPageListSize* - (input value of **nPages**)).

If the handle array is large enough to hold the handles of all the requested property sheet pages, the function:

* Adds the handles to the handle array.
* Sets **nPages** to the total number of handles in the array.
* Sets *RequiredSize* to the number of handles that it returns.
* Returns **TRUE**.

If the handle array is not large enough to hold the handles of all the specified property sheet pages, the function:

* Adds as many handles as the array can hold.
* Sets **nPages** to *PropertySheetHeaderPageListSize*.
* Sets *RequiredSize* to the total number of requested property sheet pages. The number of handles that are not returned by the function is equal to (*RequiredSize* - *PropertySheetHeaderPageListSize* - (input value of **nPages**)).
* Sets the error code to ERROR_INSUFFICIENT_BUFFER.
* Returns **FALSE**.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassDevPropertySheets as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)