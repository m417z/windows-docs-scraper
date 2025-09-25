# INewMenuClient::SelectAndEditItem

## Description

Selects or edits the specified item in the menu.

## Parameters

### `pidlItem` [in]

Type: **PCIDLIST_ABSOLUTE**

### `flags` [in]

Type: **NMCSAEI_FLAGS**

#### NMCSAEI_SELECT (0x0000)

0x0000. Select the item.

#### NMCSAEI_EDIT (0x0001)

0x0001. Edit the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.