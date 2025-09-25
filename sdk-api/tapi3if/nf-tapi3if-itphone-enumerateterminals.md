# ITPhone::EnumerateTerminals

## Description

The
**EnumerateTerminals** method retrieves an enumeration of terminals that are associated with the phone. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

## Parameters

### `pAddress` [in]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface.

### `ppEnumTerminal` [out]

Pointer to the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface that enumerates terminals.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If no terminals are associated with the phone, this method produces an empty enumeration and returns S_OK.

Although the
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function requires the handle to an open phone device, the application does not have to call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before calling
**EnumerateTerminals**. This is because the implementation of the phone object can open the phone and call
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) during TAPI initialization or when a new phone object appears.

TAPI calls the **AddRef** method on the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface returned by **ITPhone::EnumerateTerminals**. The application must call **Release** on the
**IEnumTerminal** interface to free resources associated with it.

## See also

[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)