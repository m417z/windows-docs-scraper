# IBDA_NameValueService::GetValueNameByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a name, specified by index, from the device's list of name/value pairs.

## Parameters

### `ulIndex` [in]

The zero-based index of the name to get.

### `pbstrName` [out]

Receives the name as a **BSTR**. The caller must free the **BSTR** by calling **SysFreeString**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **BDA_E_OUT_OF_BOUNDS** | The *ulIndex* parameter is out of bounds. |

## See also

[IBDA_NameValueService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_namevalueservice)