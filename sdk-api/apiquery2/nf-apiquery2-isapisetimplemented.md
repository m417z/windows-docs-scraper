# IsApiSetImplemented function

## Description

The **IsApiSetImplemented** function tests if a specified *API set* is present on the computer.

## Parameters

### `Contract`

Specifies the name of the API set to query. For more info, see the Remarks section.

## Return value

**IsApiSetImplemented** returns **TRUE** if the specified API set is present. In this case, APIs in the target API set have valid implementations on the current platform.

Otherwise, this function returns **FALSE**.

## Remarks

All versions of Windows 10 share a common base of OS components that is called the *core OS* (in some contexts this is also called *OneCore*). In core OS components, Win32 APIs are organized into functional groups called [API sets](https://learn.microsoft.com/windows/win32/apiindex/windows-apisets).

Some API sets are not available on all Windows 10 platforms. For example, although the full breadth of the Win32 API is supported on PCs, only a subset of the Win32 API is available on other devices such as HoloLens, Xbox, and other devices running Windows 10x.

When writing code that targets both desktop and non-desktop Windows 10 devices, wrap the API call in **IsApiSetImplemented**. This function tests at runtime if the API set that the API belongs to is present on the target platform. For more details see [Detect API set availability](https://learn.microsoft.com/windows/win32/apiindex/detect-api-set-availability).

To identify whether a given Win32 API belongs to an API set, review the requirements table in the reference documentation for the API. If the API belongs to an API set, the requirements table in the article lists the API set name.

## See also

[Windows API sets](https://learn.microsoft.com/windows/win32/apiindex/windows-apisets)

[Detect API set availability](https://learn.microsoft.com/windows/win32/apiindex/detect-api-set-availability)

[Building for OneCore](https://learn.microsoft.com/windows-hardware/drivers/develop/building-for-onecore)

[Validating Universal Windows drivers](https://learn.microsoft.com/windows-hardware/drivers/develop/validating-universal-drivers)