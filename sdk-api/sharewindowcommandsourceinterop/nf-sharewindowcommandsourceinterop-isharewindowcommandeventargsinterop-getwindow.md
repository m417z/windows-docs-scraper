## Description

Gets the window identifier (a window handle).

> [!IMPORTANT]
> The **IShareWindowCommandEventArgsInterop::GetWindow** API is part of a Limited Access Feature (see [LimitedAccessFeatures class](https://learn.microsoft.com/uwp/api/windows.applicationmodel.limitedaccessfeatures)). For more information or to request an unlock token, contact [Microsoft Support](https://aka.ms/LAFAccessRequests).

## Parameters

### `value`

Type: **[HWND](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The address of a **HWND** in which to receive the window identifier (a window handle).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

For a code example, see [IShareWindowCommandEventArgsInterop](https://learn.microsoft.com/windows/win32/api/sharewindowcommandsourceinterop/nn-sharewindowcommandsourceinterop-isharewindowcommandeventargsinterop).

## See also

* [IShareWindowCommandEventArgsInterop](https://learn.microsoft.com/windows/win32/api/sharewindowcommandsourceinterop/nn-sharewindowcommandsourceinterop-isharewindowcommandeventargsinterop)