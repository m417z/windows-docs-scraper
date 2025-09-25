# IDVB_ST::GetData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetData** method returns the data in the ST.

## Parameters

### `ppData` [out]

Address of a variable that receives a pointer to a buffer, which contains all of the data_byte fields in the ST. To get the size of the buffer, call the [IDVB_ST::GetDataLength](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_st-getdatalength) method. The caller must release the buffer by calling the **CoTaskMemFree** function.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |
| **S_FALSE** | The ST does not contain any data. |
| **S_OK** | The method succeeded. |

## Remarks

The data in an ST has no meaning.

## See also

[IDVB_ST Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_st)