# MI_Application_NewDeserializer function

## Description

Creates a deserializer object that can then be used to convert a serialized object back into a class
or instance.

## Parameters

### `application` [in, out]

Handle returned from
[MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1).

### `flags`

Must be 0.

### `format` [in]

A string that indicates which serializer to use. Must be L"MI_XML".

### `deserializer` [out]

The populated deserializer object.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Serializers are used to persist [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) and
[MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) objects to **BYTE** arrays.
A deserializer is then used to re-create the object from its stored form.