# IResultData::GetItem

## Description

The **IResultData::GetItem** method enables a user to retrieve the parameters of a single item.

## Parameters

### `item` [in, out]

A pointer to a
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure that contains information about the item whose parameters are being retrieved.

## Return value

This method can return one of these values.

## Remarks

The itemID member of the
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure pointed to by the item parameter should be set to refer to the item or subitem for which information is being returned. The nCol member should be set to 0 (zero) because it is the only column in which anything can be obtained or set. In addition, the data members for each of the flags set in the mask member of the structure pointed to by the item parameter if this method call succeeds will be returned.

If itemID is 0 (zero), the nIndex member can be used.

When applied to virtual lists, you must use the nIndex member and set itemID to 0 (zero). For virtual lists you can only get the select and focus states of an item.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultData::SetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-setitem)