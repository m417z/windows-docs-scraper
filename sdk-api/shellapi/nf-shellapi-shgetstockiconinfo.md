# SHGetStockIconInfo function

## Description

Retrieves information about system-defined Shell icons.

## Parameters

### `siid`

Type: **[SHSTOCKICONID](https://learn.microsoft.com/windows/desktop/api/shellapi/ne-shellapi-shstockiconid)**

One of the values from the [SHSTOCKICONID](https://learn.microsoft.com/windows/desktop/api/shellapi/ne-shellapi-shstockiconid) enumeration that specifies which icon should be retrieved.

### `uFlags`

Type: **UINT**

A combination of zero or more of the following flags that specify which information is requested.

#### SHGSI_ICONLOCATION

The **szPath** and **iIcon** members of the [SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo) structure receive the path and icon index of the requested icon, in a format suitable for passing to the [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) function. The numerical value of this flag is zero, so you always get the icon location regardless of other flags.

#### SHGSI_ICON

The **hIcon** member of the [SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo) structure receives a handle to the specified icon.

#### SHGSI_SYSICONINDEX

The **iSysImageImage** member of the [SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo) structure receives the index of the specified icon in the system imagelist.

#### SHGSI_LINKOVERLAY

Modifies the SHGSI_ICON value by causing the function to add the link overlay to the file's icon.

#### SHGSI_SELECTED

Modifies the SHGSI_ICON value by causing the function to blend the icon with the system highlight color.

#### SHGSI_LARGEICON

Modifies the SHGSI_ICON value by causing the function to retrieve the large version of the icon, as specified by the SM_CXICON and SM_CYICON system metrics.

#### SHGSI_SMALLICON

Modifies the SHGSI_ICON value by causing the function to retrieve the small version of the icon, as specified by the SM_CXSMICON and SM_CYSMICON system metrics.

#### SHGSI_SHELLICONSIZE

Modifies the SHGSI_LARGEICON or SHGSI_SMALLICON values by causing the function to retrieve the Shell-sized icons rather than the sizes specified by the system metrics.

### `psii` [in, out]

Type: **[SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo)***

A pointer to a [SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo) structure. When this function is called, the **cbSize** member of this structure needs to be set to the size of the **SHSTOCKICONINFO** structure. When this function returns, contains a pointer to a **SHSTOCKICONINFO** structure that contains the requested information.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this function returns an icon handle in the **hIcon** member of the [SHSTOCKICONINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shstockiconinfo) structure pointed to by *psii*, you are responsible for freeing the icon with [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) when you no longer need it.