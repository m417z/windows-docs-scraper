# OOBE_COMPLETED_CALLBACK callback function

## Description

Application-defined callback function used with the [RegisterWaitUntilOOBECompleted](https://learn.microsoft.com/previous-versions/windows/desktop/api/oobenotification/nf-oobenotification-registerwaituntiloobecompleted) function.

## Parameters

### `CallbackContext`

Pointer to the callback context. This is the value passed to the [RegisterWaitUntilOOBECompleted](https://learn.microsoft.com/previous-versions/windows/desktop/api/oobenotification/nf-oobenotification-registerwaituntiloobecompleted) function as the *CallbackContext* parameter.

## Remarks

Once the callback function has completed, [UnregisterWaitUntilOOBECompleted](https://learn.microsoft.com/previous-versions/windows/desktop/api/oobenotification/nf-oobenotification-unregisterwaituntiloobecompleted) should be called.