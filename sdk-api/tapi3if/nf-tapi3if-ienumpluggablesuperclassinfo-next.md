# IEnumPluggableSuperclassInfo::Next

## Description

The
**Next** method gets the next specified number of elements in the enumeration sequence. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `celt` [in]

Number of elements requested.

### `ppElements` [out]

Pointer to
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) list of pointers returned.

### `pceltFetched` [in, out]

Pointer to number of elements actually supplied. May be **NULL** if *celt* is one.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method returned *celt* number of elements. |
| **S_FALSE** | Number of elements remaining was less than *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppElements* parameter is not a valid pointer. |

## Remarks

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo) interface returned by **IEnumPluggableSuperclassInfo::Next**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the [IEnumPluggableSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggablesuperclassinfo) interface to free resources associated with it.

## See also

[IEnumPluggableSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumpluggablesuperclassinfo)

[ITPluggableTerminalSuperclassInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itpluggableterminalsuperclassinfo)