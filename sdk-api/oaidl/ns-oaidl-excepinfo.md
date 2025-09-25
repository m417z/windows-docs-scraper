# EXCEPINFO structure

## Description

Describes an exception that occurred during [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

## Members

### `wCode`

The error code. Error codes should be greater than 1000. Either this field or the scode field must be filled in; the other must be set to 0.

### `wReserved`

Reserved. Should be 0.

### `bstrSource`

The name of the exception source. Typically, this is an application name. This field should be filled in by the implementer of [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).

### `bstrDescription`

The exception description to display. If no description is available, use null.

### `bstrHelpFile`

The fully qualified help file path. If no Help is available, use null.

### `dwHelpContext`

The help context ID.

### `pvReserved`

Reserved. Must be null.

### `pfnDeferredFillIn`

Provides deferred fill-in. If deferred fill-in is not desired, this field should be set to null.

### `scode`

A return value that describes the error. Either this field or wCode (but not both) must be filled in; the other must be set to 0. (16-bit Windows versions only.)

## Remarks

Use the **pfnDeferredFillIn** field to enable an object to defer filling in the **bstrDescription**, **bstrHelpFile**, and **dwHelpContext** fields until they are needed. This field might be used, for example, if loading the string for the error is a time-consuming operation. To use deferred fill-in, the object puts a function pointer in this slot and does not fill any of the other fields except **wCode**, which is required.

To get additional information, the caller passes the **EXCEPINFO** structure back to the **pexcepinfo** callback function, which fills in the additional information. When the ActiveX object and the ActiveX client are in different processes, the ActiveX object calls **pfnDeferredFillIn** before returning to the controller.