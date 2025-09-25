# PDH_DATA_ITEM_PATH_ELEMENTS_W structure

## Description

The
**PDH_DATA_ITEM_PATH_ELEMENTS** structure contains the path elements of a specific data item.

## Members

### `szMachineName`

Pointer to a null-terminated string that specifies the name of the computer where the data item resides.

### `ObjectGUID`

GUID of the object where the data item resides.

### `dwItemId`

Identifier of the data item.

### `szInstanceName`

Pointer to a null-terminated string that specifies the name of the data item instance.

## See also

[PDH_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_counter_info_a)