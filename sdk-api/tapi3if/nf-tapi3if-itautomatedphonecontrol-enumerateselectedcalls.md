# ITAutomatedPhoneControl::EnumerateSelectedCalls

## Description

The
**EnumerateSelectedCalls** method retrieves an enumerator object indicating which calls are currently selected on this phone. See
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) for more information.

This method is intended for C and C++ programmers. Applications written in Visual Basic, Java, or various scripting languages should use the
[get_SelectedCalls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_selectedcalls) method instead.

## Parameters

### `ppCallEnum` [out]

Pointer to the
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

TAPI calls the **AddRef** method on the
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface returned by this method. The application must call the **Release** method on the
**IEnumCall** interface to free resources associated with it.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)