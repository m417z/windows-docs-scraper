# ITravelLog::InsertMenuEntries

## Description

Deprecated. Inserts entries into the specified menu.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

### `hmenu` [in]

Type: **HMENU**

The handle of the menu.

### `nPos` [in]

Type: **int**

The position in the menu to insert the entries.

### `idFirst` [in]

Type: **int**

The ID of the first entry to be inserted.

### `idLast` [in]

Type: **int**

The ID of the last entry to be inserted. The difference between *idFirst* and *idLast* is the maximum number of entries that can be inserted into the menu.

### `dwFlags` [in]

Type: **DWORD**

The types of entries to add to the menu. Includes the following:

#### TLMENUF_INCLUDECURRENT

Include the current page.

#### TLMENUF_CHECKCURRENT

Add a check mark next to the entry of the current page.

#### TLMENUF_BACK

Default. The previous pages.

#### TLMENUF_FORE

The next pages.

#### TLMENUF_BACKANDFORTH

Previous, current, and next pages.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.