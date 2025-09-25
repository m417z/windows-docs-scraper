# GetThemeBackgroundContentRect function

## Description

Retrieves the size of the content area for the background defined by the visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to use when drawing. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the content area. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part that contains the content area. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pBoundingRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the total background rectangle, in logical coordinates. This is the area inside the borders or margins.

### `pContentRect` [out]

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the content area background rectangle, in logical coordinates. This rectangle is calculated to fit the content area.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A visual style can define a content area within each background image. This is the area where content such as text and icons can be placed without overwriting background borders.

#### Examples

When applying a theme to an entire client area of a window, you can call [GetClientRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclientrect) to retrieve this area in a **RECT**, which can be passed via pointer as the *pContentRect* parameter to **GetThemeBackgroundContentRect** as in the following example.

```cpp
DWORD resultFlags = GetThemeAppProperties();
bool ctrlsAreThemed = ((resultFlags & STAP_ALLOW_CONTROLS) != 0);

```

## See also

[GetThemeBackgroundExtent](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemebackgroundextent)

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)

**Reference**