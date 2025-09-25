# ITAutomatedPhoneControl::get_SelectedCalls

## Description

The
**get_SelectedCalls** method retrieves a VARIANT containing a pointer to a collection object indicating which calls are currently selected on this phone. See
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) for more information.

This method is intended for applications written in Visual Basic, Java, or various scripting languages. C and C++ programmers should use the
[EnumerateSelectedCalls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-enumerateselectedcalls) method instead.

## Parameters

### `pVariant` [out]

Pointer to a VARIANT containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface pointers.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[EnumerateSelectedCalls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-enumerateselectedcalls)

[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall)

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)