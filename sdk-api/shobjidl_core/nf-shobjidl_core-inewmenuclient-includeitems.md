# INewMenuClient::IncludeItems

## Description

Allows the view to filter the items shown in the menu.

## Parameters

### `pflags` [out]

Type: **NMCII_FLAGS***

Pointer to a value that, when this method returns successfully, contains one of the following values:

#### NMCII_NONE (0x0000)

0x0000.

#### NMCII_ITEMS (0x0001)

0x0001. Non-folder items.

#### NMCII_FOLDERS (0x0002)

0x0002. Folder items.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.