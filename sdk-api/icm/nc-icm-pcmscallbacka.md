## Description

\**PCMSCALLBACKA** (or **ApplyCallbackFunction**) is a callback function that you implement that updates the WCS configuration data while the dialog box displayed by the [**SetupColorMatchingW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setupcolormatchingw) function is executing. The name **ApplyCallbackFunction** is a placeholder. The actual name of this callback function is supplied by your application using ICM.

## Parameters

### `unnamedParam1`

Pointer to a [**COLORMATCHSETUPW**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-colormatchsetupw) structure that contains WCS configuration data.

### `unnamedParam2`

Contains a value supplied by the application.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. The callback function can set the extended error information by calling [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror).

## Remarks

The **ApplyCallbackFunction** function is used to change the WCS configuration for a device while the Color Management dialog box is displayed. The Color Management dialog box is displayed by the [**SetupColorMatchingW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setupcolormatchingw) function.

If the callback function is provided, an **Apply** button is displayed in the lower right of the dialog box. When you select the **Apply** button, the callback function immediately updates the configuration for the device being set up. The Color Management dialog box remains on the screen.

An application supplies a callback function to WCS by storing the address of the callback function in the [**COLORMATCHSETUPW**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-colormatchsetupw) structure that is passed to the [**SetupColorMatchingW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setupcolormatchingw) function. The address is stored in the [**lPfnApplyCallback**](https://www.bing.com/search?q=**lPfnApplyCallback**) member of the **COLORMATCHSETUP** structure. The **dwFlags** member should be set to CMS\_USEAPPLYCALLBACK, or the callback function will be ignored.

A value supplied by the application may be passed to the callback function. Prior to invoking the [**SetupColorMatchingW**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setupcolormatchingw) function, the application can store a value in the [**lParamApplyCallback**](https://www.bing.com/search?q=**lParamApplyCallback**) member of the [**COLORMATCHSETUPW**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-colormatchsetupw) structure. When the callback function is invoked, the value in the **lParamApplyCallback** structure member will be passed to the callback function in its *lParam* parameter.

The callback function is completely optional. If it is not supplied, the **Apply** button does not appear in the Color Management dialog box. Microsoft strongly recommends that your application supplies a callback function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [SetupColorMatchingW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setupcolormatchingw)
* [COLORMATCHSETUPW](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-colormatchsetupw)