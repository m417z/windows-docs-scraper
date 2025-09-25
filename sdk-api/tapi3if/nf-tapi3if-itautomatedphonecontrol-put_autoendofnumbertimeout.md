# ITAutomatedPhoneControl::put_AutoEndOfNumberTimeout

## Description

The
**put_AutoEndOfNumberTimeout** method sets the value of the **AutoEndOfNumberTimeout** property. The property specifies how long to wait after a digit has been pressed before it is assumed that the entire number has been gathered.

## Parameters

### `lTimeout` [in]

Timeout interval to wait, in milliseconds (ms). The default value is 3000 ms.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

A value of 0 turns off this timeout and bases the end-of-number detection solely on the user pressing the # or SEND buttons.

End-of-number-detection ceases (without a detection event) when an invocation of
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) succeeds, and detection remains suspended until the call is unselected.

The **AutoEndOfNumberTimeout** property controls only what happens after at least one keypad button has been pressed.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)

[get_AutoEndOfNumberTimeout](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autoendofnumbertimeout)