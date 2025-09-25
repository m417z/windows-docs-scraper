# MI_Application_NewSerializer function

## Description

Retrieves a serializer object that can then be used to serialize instances and classes into various different formats.

## Parameters

### `application` [in, out]

A pointer to a handle returned from the [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1) function.

### `flags`

This parameter must be 0.

### `format` [in]

A string that contains which serializer to use. This parameter must be L"MI_XML".

### `serializer` [out]

The returned serializer object.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Serializers are used to persist [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) and [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) objects. A deserializer is then used to re-create the object from its stored form.