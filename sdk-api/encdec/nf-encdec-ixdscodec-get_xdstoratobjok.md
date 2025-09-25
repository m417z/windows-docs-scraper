# IXDSCodec::get_XDSToRatObjOK

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_XDSToRatObjOK** method queries whether the **XDSToRat** object was created successfully.

## Parameters

### `pHrCoCreateRetVal` [out, retval]

Receives an **HRESULT** value. The **HRESULT** is the value that was returned when the filter called **CoCreateInstance** to create the **XDSToRat** object. If it equals S_OK, the **EvalRat** object was created successfully.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument |
| **S_OK** | Success |

## See also

[IXDSCodec Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodec)