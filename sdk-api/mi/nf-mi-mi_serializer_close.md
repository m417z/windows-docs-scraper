# MI_Serializer_Close function

## Description

Closes a serializer object and frees any internal memory associated with it.

## Parameters

### `serializer` [in, out]

A pointer to a serializer returned from the [MI_Application_NewSerializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newserializer) function.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function should be called if there are no more active calls into the serializer.

## See also

[MI_Application_NewSerializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newserializer)